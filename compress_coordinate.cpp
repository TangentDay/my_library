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

VI compress_coordinate(VI x, VI &xc){
    int n = x.size();
    REP(i,n) xc.push_back(x[i]);
    sort(ALL(xc));
    xc.erase(unique(ALL(xc)), xc.end());
    map<int,int> mp;
    REP(i,xc.size()) mp[xc[i]] = i;
    REP(i,n) x[i] = mp[x[i]];
    return x;
}


map<int, int> zip;
VI unzip;
void compress_coordinate(VI x){
    int n = x.size();
    REP(i,n) unzip.push_back(x[i]);
    sort(ALL(unzip));
    unzip.erase(unique(ALL(unzip)), unzip.end());
    REP(i,unzip.size()) zip[unzip[i]] = i;
}

int main() {

    return 0;
}