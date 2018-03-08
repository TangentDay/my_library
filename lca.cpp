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

VI e[100000];
int par[100000][18], depth[100000];

void dfs(int now, int past){
    REP(i,e[now].size()){
        int next = e[now][i];
        if (next == past) continue;
        par[next][0] = now;
        depth[next] = depth[now] + 1;
        dfs(next, now);
    }
}

int lca(int x, int y){
    if (depth[y] > depth[x]) swap(x,y);
    int d = depth[x] - depth[y];
    REP(i,18){
        if ((d>>i) & 1){
            x = par[x][i];
        }
    }
    if (x == y) return x;
    FORR(i,17,0){
        if (par[x][i] != par[y][i]){
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

int main(){
    int n;
    cin >> n;
    REP(i,n-1){
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    par[0][0] = 0;
    depth[0] = 0;
    dfs(0, -1);

    FOR(i,1,17){
        REP(j,n){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    return 0;
}