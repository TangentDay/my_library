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

// 0 - indexed
struct BIT2D{
    int n, m;
    VVL dat;

    BIT2D(){}
    BIT2D(int x, int y){
        n = x;
        m = y;
        dat.assign(n+1, VL(m+1));
    }

    void init(int x, int y){
        n = x;
        m = y;
        dat.assign(n+1, VL(m+1));
    }

    void add(int x, int y, ll v){
        x++;
        y++;
        for (int i = x; i <= n; i += i & -i) {
            for(int j = y; j <= m; j += j & -j) {
                dat[i][j] += v;
            }
        }
    }

    // [0, x] * [0, y]
    ll sum(int x, int y){
        x++;
        y++;
        ll ret = 0;
        for(int i = x; i > 0; i -= i & -i) {
            for(int j = y; j > 0; j -= j & -j) {
                ret += dat[i][j];
            }
        }
        return ret;
    }

    // [x0, x1] * [y0 * y1]
    ll sum(int x0, int y0, int x1, int y1){
        return sum(x1, y1) - sum(x0-1, y1) - sum(x1, y0-1) + sum(x0-1, y0-1);
    }
};
