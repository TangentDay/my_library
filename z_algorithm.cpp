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

VI Z_algorithm(string s){
    int n = s.length();
    VI a(n);
    a[0] = n;
    for (int i = 1, j = 0; i < n;){
        while (i + j < n && s[j] == s[i + j]) j++;
        a[i] = j;
        if (j == 0){
            i++;
            continue;
        }
        int k = 1;
        while (i + k < n && k + a[k] < j) a[i + k] = a[k], k++;
        i += k;
        j -= k;
    }
    return a;
}
