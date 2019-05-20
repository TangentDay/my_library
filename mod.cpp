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

const ll mod = 1000000007;
const int N = 200010;
ll fact[N], invf[N];

ll add(ll x, ll y){
    return (x+y)%mod;
}

ll mul(ll x, ll y){
    return (x%mod)*(y%mod)%mod;
}

ll powll(ll x, ll y){
    x %= mod;
    ll res = 1LL;
    while(y){
        if (y & 1LL)
            res *= x;
        res %= mod;
        x = (x*x) % mod;
        y >>= 1LL;
    }
    return res;
}

ll divll(ll x, ll y){
    return (x * powll(y,mod-2)) % mod;
}

ll nPr(ll n, ll r){
    if (n < r || r < 0) return 0;
    return mul(fact[n], invf[n-r]);
}

ll nCr(ll n, ll r){
    if (n < r || r < 0) return 0;
    return mul(mul(fact[n], invf[r]), invf[n-r]);
}

VVL mulmat(VVL A, VVL B){
    int n = A.size();
    VVL C(n, VL(n));
    REP(i,n) REP(j,n) REP(k,n) (C[i][j] += A[i][k] * B[k][j]) %= mod;
    return C;
}

VVL powmat(VVL A, ll x){
    int n = A.size();
    VVL B(n, VL(n));
    REP(i,n) B[i][i] = 1;
    while (x) {
        if (x & 1) B = mulmat(B, A);
        A = mulmat(A, A);
        x >>= 1;
    }
    return B;
}

int main() {
    fact[0] = invf[0] = 1;
    FOR(i,1,N-1){
        fact[i] = (fact[i-1] * i) % mod;
        invf[i] = divll(invf[i-1], i);
    }
    return 0;
}
