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
typedef vector<double> VD;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

VI Centroid(VVI &graph){
    int n = graph.size();
    VI ret, sz(n);
    function<void (int, int)> dfs = [&](int now, int past){
        sz[now] = 1;
        bool is_centroid = true;
        for (int next : graph[now]){
            if (next == past) continue;
            dfs(next, now);
            sz[now] += sz[next];
            if (sz[next] > n / 2) is_centroid = false;
        }
        if (n - sz[now] > n / 2) is_centroid = false;
        if (is_centroid) ret.push_back(now);
    };
    dfs(0, -1);
    return ret;
}

VI Centroid(int root, VVI &graph, vector<bool> &dead){
    int n = graph.size();
    static VI sz(n);
    function<void (int, int)> get_sz = [&](int now, int past){
        sz[now] = 1;
        for (int next : graph[now]){
            if (next == past || dead[next]) continue;
            get_sz(next, now);
            sz[now] += sz[next];
        }
    };
    get_sz(root, -1);
    int m = sz[root];
    VI ret;
    function<void (int, int)> dfs = [&](int now, int past){
        bool is_centroid = true;
        for (int next : graph[now]){
            if (next == past || dead[next]) continue;
            dfs(next, now);
            if (sz[next] > m / 2) is_centroid = false;
        }
        if (m - sz[now] > m / 2) is_centroid = false;
        if (is_centroid) ret.push_back(now);
    };
    dfs(root, -1);
    return ret;
}

int OneCentroid(int root, VVI &graph, vector<bool> &dead){
    int n = graph.size();
    static VI sz(n);
    function<void (int, int)> get_sz = [&](int now, int past){
        sz[now] = 1;
        for (int next : graph[now]){
            if (next == past || dead[next]) continue;
            get_sz(next, now);
            sz[now] += sz[next];
        }
    };
    get_sz(root, -1);
    int m = sz[root];
    VI ret;
    function<int (int, int)> dfs = [&](int now, int past){
        bool is_centroid = true;
        for (int next : graph[now]){
            if (next == past || dead[next]) continue;
            if (sz[next] > m / 2) return dfs(next, now);
        }
        return now;
    };
    return dfs(root, -1);
}

void CentroidDecomposition(VVI &graph){
    int n = graph.size();
    vector<bool> dead(n);
    function<void (int)> rec = [&](int start){
        int c = OneCentroid(start, graph, dead);
        dead[c] = true;
        // do it
        for (int u : graph[c]){
            if (!dead[u]) rec(u);
        }
        dead[c] = false;
    };
    rec(0);
}
