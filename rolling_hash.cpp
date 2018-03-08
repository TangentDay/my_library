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
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

struct RollingHash{
    int n;
    ll mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    ll base1 = 1007, base2 = 1009;
    VL hash1, hash2, pow1, pow2;

    void init(string s){
        n = s.length();
        hash1.assign(n+1, 0);
        hash2.assign(n+1, 0);
        pow1.assign(n+1, 1);
        pow2.assign(n+1, 1);
        REP(i,n){
            hash1[i+1] = (hash1[i] * base1 + s[i]) % mod1;
            hash2[i+1] = (hash2[i] * base2 + s[i]) % mod2;
            pow1[i+1] = (pow1[i] * base1) % mod1;
            pow2[i+1] = (pow2[i] * base2) % mod2;
        }
    }

    // [l, r)
    PL hash(int l, int r){
        ll h1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        ll h2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return PL(h1, h2);
    }

    bool match(int l1, int r1, int l2, int r2){
        if (r1 > n || r2 > n) return false;
        return hash(l1, r1) == hash(l2, r2);
    }

    bool match(int l1, int l2, int k){
        return match(l1, l1 + k, l2, l2 + k);
    }

    int lcp(int l1, int l2){
        int ok = 0, ng = n;
        while (ng - ok > 1){
            int m = (ok + ng) / 2;
            if (match(l1, l2, m)) ok = m;
            else ng = m;
        }
        return ok;
    }
};

int main() {
    string s;
    cin >> s;
    int n = s.length();

    RollingHash rh;
    rh.init(s);

    return 0;
}