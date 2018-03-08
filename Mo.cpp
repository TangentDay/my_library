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
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    int n, q;
    cin >> n >> q;
    VI left(q), right(q);
    REP(i,q){
        scanf("%d %d", &left[i], &right[i]);
        left[i]--;
        right[i]--;
    }

    int width = sqrt(n);
    VI ord(q);
    REP(i,q) ord[i] = i;
    sort(begin(ord), end(ord), [&](int a, int b)
    {
        if(left[a] / width != left[b] / width) return left[a] < left[b];
        return right[a] < right[b];
    });

    VL ans(q);
    ll sum = 1;
    int x = 0, y = 0;
    REP(j,q){
        int i = ord[j];
        while (x > left[i]){
            x--;
        }
        while (y < right[i]){
            y++;
        }
        while (x < left[i]){
            x++;
        }
        while (y > right[i]){
            y--;
        }
        ans[i] = sum;
    }

    return 0;
}