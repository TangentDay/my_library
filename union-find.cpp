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

struct union_find{
    VI par, sz;

    void init(int n){
        par.resize(n);
        REP(i,n) par[i] = i;
        sz.assign(n, 1);
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
        sz[y] += sz[x];
    }

    int size(int x){
        return sz[find(x)];
    }
};

struct persistent_union_find{
    VI par, rank;
    VI par_saved, rank_saved;
    set<int> changed;

    void init(int n){
        par.resize(n);
        rank.resize(n);
        par_saved.resize(n);
        rank_saved.resize(n);
        REP(i,n) par[i] = par_saved[i] = i;
    }

    int find(int x){
        if (par[x] == x) return x;
        else return find(par[x]);
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return;

        changed.insert(x);
        changed.insert(y);

        if (rank[x] < rank[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    void save(){
        for (int x : changed){
            par_saved[x] = par[x];
            rank_saved[x] = rank[x];
        }
        changed.clear();
    }

    void load(){
        for (int x : changed){
            par[x] = par_saved[x];
            rank_saved[x] = rank[x];
        }
        changed.clear();
    }
};