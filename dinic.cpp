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
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

struct edge{
    int to, cap, rev;
};

struct Dinic{
    const int INF = 1e9;
    int n;
    vector<vector<edge> > g;
    VI level, iter;

    void init(int x){
        n = x;
        g.resize(n);
        level.resize(n);
        iter.resize(n);
    }

    void add_edge(int from, int to, int cap){
        g[from].push_back((edge){to, cap, (int)g[to].size()});
        g[to].push_back((edge){from, 0, (int)g[from].size() - 1});
    }

    void bfs(int s){
        fill(ALL(level), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()){
            int v = que.front();
            que.pop();
            for (edge &e : g[v]){
                if (e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f){
        if (v == t) return f;
        for (int &i = iter[v]; i < g[v].size(); i++){
            edge &e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]){
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0){
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t){
        int flow = 0;
        while (1){
            bfs(s);
            if (level[t] < 0) return flow;
            fill(ALL(iter), 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0){
                flow += f;
            }
        }
    }
};