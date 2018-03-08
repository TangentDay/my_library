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
#include <array>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

const int N = 100000;
int low[N], pre[N];
vector<P> bridge;
int cnt;

void dfs(int now, int past){
    pre[now] = cnt++;
    low[now] = pre[now];
    for (int next : e[now]){
        if (next == past) continue;
        if (pre[next] == -1){
            dfs(next, now);
            if (low[next] == pre[next]){
                bridge.push_back(P(now, next));
            }
        }
        low[now] = min(low[now], low[next]);
    }
}