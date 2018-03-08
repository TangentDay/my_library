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

VI slide_min(VI a, int k){
    VI ret;
    deque<int> dq;
    REP(i,a.size()){
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
        if (i - k + 1 >= 0){
            ret.push_back(a[dq.front()]);
            if (dq.front() == i - k + 1) dq.pop_front();
        }
    }
    return ret;
}

int main(){
    int n, k;
    cin >> n >> k;
    VI a(n);
    REP(i,n) scanf("%d", &a[i]);

    VI b = slide_min(a, k);

    return 0;
}