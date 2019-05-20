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
#include <array>
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
typedef vector<double> VD;
typedef vector<VD> VVD;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

VI tree_diameter(VVI &e){
    int n = e.size();
    VI dist(n, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while (!que.empty()){
        int x = que.front();
        que.pop();
        for (int y : e[x]){
            if (dist[y] == -1){
                dist[y] = dist[x] + 1;
                que.push(y);
            }
        }
    }
    int r = max_element(ALL(dist)) - dist.begin();
    dist.assign(n, -1);
    que.push(r);
    dist[r] = 0;
    while (!que.empty()){
        int x = que.front();
        que.pop();
        for (int y : e[x]){
            if (dist[y] == -1){
                dist[y] = dist[x] + 1;
                que.push(y);
            }
        }
    }
    int s = max_element(ALL(dist)) - dist.begin();
    VI ret;
    while (s != r){
        ret.push_back(s);
        for (int x : e[s]){
            if (dist[x] == dist[s] - 1){
                s = x;
                break;
            }
        }
    }
    ret.push_back(r);
    return ret;
}
