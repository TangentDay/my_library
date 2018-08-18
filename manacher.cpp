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

VI Manacher(string s){
    int n = s.length();
    VI a(n);
    for (int i = 0, j = 0; i < n;){
        while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) j++;
        a[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < n && k + a[i - k] < j) a[i + k] = a[i - k], k++;
        i += k;
        j -= k;
    }
    return a;
}
