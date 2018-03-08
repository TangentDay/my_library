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

struct union_find{
    VI par;

    void init(int n){
        par.resize(n);
        REP(i,n) par[i] = i;
    }

    int find(int x){
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return;
        par[x] = y;
    }
};

struct edge{ int u, v, cost; };

bool comp(const edge &e1, const edge &e2){
    return e1.cost < e2.cost;
}

int kruskal(vector<edge> &es, int n){
    sort(es.begin(), es.end(), comp);
    union_find uf;
    uf.init(n);
    int res = 0;
    REP(i,es.size()){
        edge e = es[i];
        if (!uf.same(e.u, e.v)){
            uf.merge(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}