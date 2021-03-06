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

int main(void) {
    int n;
    cin >> n;
    VL a(n);

    VL dp(n+1,1e18);
    REP(i,n){
        *lower_bound(ALL(dp), a[i]) = a[i];
    }
    cout << lower_bound(ALL(dp), 1e18) - dp.begin() << endl;
    return 0;
}