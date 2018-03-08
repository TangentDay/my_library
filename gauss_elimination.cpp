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
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int gauss_elimination(VVI &A, VVI &B){
    int n = A.size(), m = A[0].size(), p = B[0].size();

    int r = 0;
    REP(j,m){
        FOR(i,r,n-1){
            if (A[i][j]){
                swap(A[r], A[i]);
                swap(B[r], B[i]);
                break;
            }
        }
        if (A[r][j] == 0) continue;
        FOR(i,r+1,n-1){
            int k = A[i][j] / A[r][j];
            FOR(jj,j,m-1){
                A[i][jj] = (A[i][jj] - k * A[r][jj]);
            }
            REP(jj,p){
                B[i][jj] = (B[i][jj] - k * B[r][jj]);
            }
        }
        r++;
        if (r == n) break;
    }
    return r;
}