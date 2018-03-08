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

ll max_rect(VL a){
    int n = a.size();
    VI l(n), r(n);

    stack<int> st;
    REP(i,n){
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        l[i] = (st.empty() ? 0 : st.top() + 1);
        st.push(i);
    }

    while (!st.empty()) st.pop();
    FORR(i,n-1,0){
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        r[i] = (st.empty() ? n : st.top());
        st.push(i);
    }

    ll ret = 0;
    REP(i,n){
        ret = max(ret, a[i] * (r[i] - l[i]));
    }
    return ret;
}