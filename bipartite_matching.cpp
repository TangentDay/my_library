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

struct bipartite_matching{
    int n, x, y;
    VVI e;
    VI match;
    vector<bool> used;

    void init(int a, int b){
        x = a;
        y = b;
        n = x + y;
        e.resize(n);
        match.resize(n);
        used.resize(n);
    }

    void add_edge(int u, int v){
        e[u].push_back(v + x);
        e[v + x].push_back(u);
    }

    bool dfs(int v){
        used[v] = true;
        for (int u : e[v]){
            int w = match[u];
            if (w < 0 || (!used[w] && dfs(w))){
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    int calc_matching(){
        int res = 0;
        fill(ALL(match), -1);
        REP(v,n){
            if (match[v] < 0){
                used.assign(n, 0);
                if (dfs(v)) res++;
            }
        }
        return res;
    }
};
