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
#define pi acos(-1.0)

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

#define INF 1e9

int d[300][300];

void warshall_floyd(int n){
    REP(i,n) REP(j,n) REP(k,n) d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main(){
    int n, m;
    cin >> n >> m;
    REP(i,n) REP(j,n) d[i][j] = INF * (i != j);
    REP(i,m){
        int u, v, l;
        scanf("%d %d %d", &u, &v, &l);
        u--;
        v--;
        d[u][v] = d[v][u] = l;
    }

    warshall_floyd(n);

    return 0;
}