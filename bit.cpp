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
        bit.assign(n+1, 0);
    }

    void init(int x){
        n = x;
        bit.assign(n+1, 0);
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