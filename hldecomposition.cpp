#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) c.begin(), c.end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

struct BIT{
    int n;
    VL bit;

    BIT(){}
    BIT(int x){
        n = x;
        bit.resize(x+1);
    }

    void init(int x){
        n = x;
        bit.resize(x+1);
    }

    void add(int i, ll x){
        i++;
        while (i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }

    // [0, i]
    ll sum(int i){
        i++;
        ll ret = 0;
        while (i > 0){
            ret += bit[i];
            i -= i & -i;
        }
        return ret;
    }

    // [l, r)
    ll sum(int l, int r){
        if (l >= r) return 0;
        return sum(r-1) - sum(l-1);
    }
};

struct HLDecomposition{
    int n;
    VVI e;
    VI par, depth, heavy, vid, inv, head;
    BIT bit;

    HLDecomposition(int m){
        n = m;
        e.resize(m);
        par.resize(m);
        depth.resize(m);
        heavy.resize(m,-1);
        vid.resize(m,-1);
        inv.resize(m);
        head.resize(m);
        bit.init(m);
    }
    
    void add_edge(int u, int v){
        e[u].push_back(v);
        e[v].push_back(u);
    }

    void construct(){
        dfs(0, -1);
        bfs();
    }

    int dfs(int now, int past){
        par[now] = past;
        int sub = 1, sub_max = 0;
        for (int next : e[now]){
            if (next == past) continue;
            depth[next] = depth[now] + 1;
            int sub_next = dfs(next, now);
            sub += sub_next;
            if (sub_max < sub_next){
                sub_max = sub_next;
                heavy[now] = next;
            }
        }
        return sub;
    }

    void bfs(){
        int id = 0;
        queue<int> que;
        que.push(0);
        while (!que.empty()){
            int h = que.front();
            que.pop();
            for (int i = h; i != -1; i = heavy[i]){
                vid[i] = id++;
                inv[vid[i]] = i;
                head[i] = h;
                for (int j : e[i]){
                    if (j != par[i] && j != heavy[i]) que.push(j);
                }
            }
        }
    }

    ll calc_v(int u, int v){
        if (vid[u] > vid[v]) swap(u, v);
        ll ret = bit.sum(max(vid[head[v]], vid[u]), vid[v]+1);
        if (head[u] != head[v])  ret += calc_v(u, par[head[v]]);
        return ret;
    }

    // 深い方の頂点に足しておく
    ll calc_e(int u, int v){
        if (vid[u] > vid[v]) swap(u, v);
        ll ret = bit.sum(max(vid[head[v]], vid[u]+1), vid[v]+1);
        if (head[u] != head[v])  ret += calc_e(u, par[head[v]]);
        return ret;
    }

    int lca(int u, int v){
        if (vid[u] > vid[v]) swap(u, v);
        if (head[u] == head[v]) return u;
        return lca(u, par[head[v]]);
    }

    int dist(int u, int v){
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};