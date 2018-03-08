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

// RMQ ans RUQ
struct SqrtDecomposition{
    const int INF = (1LL << 31) - 1;
    int n, sqrtn, k;
    VI dat, buk, lazy;
    vector<bool> lazyflag;

    void init(int x){
        n = x;
        sqrtn = sqrt(n);
        k = (n + sqrtn - 1) / sqrtn;
        dat.assign(sqrtn * k, INF);
        buk.assign(k, INF);
        lazy.assign(k, 0);
        lazyflag.assign(k, false);
    }

    void eval(int b){
        if (!lazyflag[b]) return;
        lazyflag[b] = false;
        FOR(i, sqrtn * b, sqrtn * (b+1) - 1){
            dat[i] = lazy[b];
        }
    }

    // [l, r)
    void update(int l, int r, int x){
        REP(b,k){
            int p = sqrtn * b;
            int q = sqrtn * (b+1);
            if (q <= l || r <= p) continue;
            if (l <= p && q <= r){
                buk[b] = x;
                lazyflag[b] = true;
                lazy[b] = x;
            }else{
                eval(b);
                FOR(i,max(l,p),min(r,q)-1){
                    dat[i] = x;
                }
                buk[b] = INF;
                FOR(i,p,q-1){
                    buk[b] = min(buk[b], dat[i]);
                }
            }
        }
    }

    // [l, r)
    int query(int l, int r){
        int ret = INF;
        REP(b,k){
            int p = sqrtn * b;
            int q = sqrtn * (b+1);
            if (q <= l || r <= p) continue;
            if (l <= p && q <= r){
                ret = min(ret, buk[b]);
            }else{
                eval(b);
                FOR(i,max(l,p),min(r,q)-1){
                    ret = min(ret, dat[i]);
                }
            }
        }
        return ret;
    }
};


// RMQ and RAQ
struct SqrtDecomposition2{
    const ll INF = 1e18;
    int n, sqrtn, k;
    VL dat, buk, lazy;
    vector<bool> lazyflag;

    void init(int x){
        n = x;
        sqrtn = sqrt(n);
        k = (n + sqrtn - 1) / sqrtn;
        dat.assign(sqrtn * k, 0);
        buk.assign(k, 0);
        lazy.assign(k, 0);
        lazyflag.assign(k, false);
    }

    void eval(int b){
        if (!lazyflag[b]) return;
        lazyflag[b] = false;
        FOR(i, sqrtn * b, sqrtn * (b+1) - 1){
            dat[i] += lazy[b];
        }
        lazy[b] = 0;
    }

    // [l, r)
    void update(int l, int r, ll x){
        REP(b,k){
            int p = sqrtn * b;
            int q = sqrtn * (b+1);
            if (q <= l || r <= p) continue;
            if (l <= p && q <= r){
                buk[b] += x;
                lazyflag[b] = true;
                lazy[b] += x;
            }else{
                eval(b);
                FOR(i,max(l,p),min(r,q)-1){
                    dat[i] += x;
                }
                buk[b] = INF;
                FOR(i,p,q-1){
                    buk[b] = min(buk[b], dat[i]);
                }
            }
        }
    }

    // [l, r)
    ll query(int l, int r){
        ll ret = INF;
        REP(b,k){
            int p = sqrtn * b;
            int q = sqrtn * (b+1);
            if (q <= l || r <= p) continue;
            if (l <= p && q <= r){
                ret = min(ret, buk[b]);
            }else{
                eval(b);
                FOR(i,max(l,p),min(r,q)-1){
                    ret = min(ret, dat[i]);
                }
            }
        }
        return ret;
    }
};