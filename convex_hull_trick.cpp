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
#define pi acos(-1.0)

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

struct ConvexHullTrick{
    vector<PL> ls;    // a*x + b;

    ll get(int k, ll x){
        return ls[k].first * x + ls[k].second;
    }

    bool check(PL l1, PL l2, PL l3){  // l2 can be min ?
        return (l2.first - l1.first) * (l3.second - l2.second)
                 >= (l2.second - l1.second) * (l3.first - l2.first);
    }

    void add(ll a, ll b){   // a must be decreasing
        PL l(a, b);
        while (ls.size() >= 2 && check(ls[ls.size()-2], ls[ls.size()-1], l)) ls.pop_back();
        ls.push_back(l);
    }

    ll query(ll x){ // get min at x
        int lo = -1, hi = ls.size()-1;
        while (hi - lo > 1){
            int mi = (lo + hi) / 2;
            (get(mi, x) >= get(mi + 1, x) ? lo : hi) = mi;
        }
        return get(hi, x);
    }
};
