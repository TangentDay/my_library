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
#include <bitset>
#include <algorithm>
#include <complex>
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

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

// add and min
struct LazySegmentTree{
    int n, width;
    VL dat, lazy;
    const ll INF = 1e18;

    LazySegmentTree(VL v){
        int n = v.size();
        width = 1;
        while (width < n) width *= 2;
        dat.assign(2 * width - 1, INF);
        lazy.assign(2 * width - 1, 0);
        REP(i,n) dat[i + width - 1] = v[i];
        FORR(i,width-2,0) dat[i] = min(dat[2 * i + 1], dat[2 * i + 2]);
    }

    void eval(int k, int l, int r){
        dat[k] += lazy[k];
        if (r - l > 1){
            lazy[2 * k + 1] += lazy[k];
            lazy[2 * k + 2] += lazy[k];
        }
        lazy[k] = 0;
    }

    void add(int a, int b, ll x, int k, int l, int r){
        eval(k, l, r);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b){
            lazy[k] += x;
            eval(k, l, r);
        }else{
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }

    // [l, r) += x
    void add(int l, int r, ll x){
        add(l, r, x, 0, 0, width);
    }

    ll query(int a, int b, int k, int l, int r){
        eval(k, l, r);
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return dat[k];
        ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

    ll query(int l, int r){
        return query(l, r, 0, 0, width);
    }
};
