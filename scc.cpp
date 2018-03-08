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
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

struct SCC{
    int n;
    VVI G, rG;
    VI vs, cmp;
    vector<bool> used;

    SCC(){}
    SCC(int x){
        n = x;
        G.resize(n);
        rG.resize(n);
        cmp.resize(n);
        used.resize(n);
    }

    void add_edge(int from, int to){
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v){
        used[v] = true;
        for (int next : G[v]){
            if (!used[next]) dfs(next);
        }
        vs.push_back(v);
    }

    void rdfs(int v, int k){
        used[v] = true;
        cmp[v] = k;
        for (int next : rG[v]){
            if (!used[next]) rdfs(next, k);
        }
    }

    VI scc(){
        fill(ALL(used), false);
        vs.clear();
        REP(i,n) if (!used[i]) dfs(i);
        fill(ALL(used), false);
        int k = 0;
        FORR(i,n-1,0) if (!used[vs[i]]) rdfs(vs[i], k++);
        return cmp;
    }
};