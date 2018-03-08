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

// RMQ
struct SegmentTree{
    const int INF = 1e9;
    int n, width;
    VI dat;

    void init(int x){
        n = x;
        width = 1;
        while (width < n) width *= 2;
        dat.resize(2*width-1);
        REP(i,2*width-1) dat[i] = INF;
    }

    void update(int i, int x){
        i += width - 1;
        dat[i] = x;
        while (i > 0){
            i = (i - 1) / 2;
            dat[i] = min(dat[i*2+1], dat[i*2+2]);
        }
    }

    int query(int a, int b, int k, int l, int r){
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return dat[k];
        int vl = query(a, b, k*2+1, l, (l+r)/2);
        int vr = query(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }

    // [l, r)
    int query(int l, int r){
        return query(l, r, 0, 0, width);
    }
};


// RMQ template
template<typename T>
struct SegmentTree{
    const T INF = 1e9;
    int n, width;
    vector<T> dat;

    void init(int x){
        n = x;
        width = 1;
        while (width < n) width *= 2;
        dat.assign(2*width-1, INF);
    }

    void update(int i, T x){
        i += width - 1;
        dat[i] = x;
        while (i > 0){
            i = (i - 1) / 2;
            dat[i] = min(dat[i*2+1], dat[i*2+2]);
        }
    }

    T query(int a, int b, int k, int l, int r){
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return dat[k];
        T vl = query(a, b, k*2+1, l, (l+r)/2);
        T vr = query(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }

    // [l, r)
    T query(int l, int r){
        return query(l, r, 0, 0, width);
    }
};