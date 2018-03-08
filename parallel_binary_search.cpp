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

struct query{
    int ok, ng;
    VI id;
};

void parallel_binaray_search(){
    int q = 1;
    VI id(q), ans(q);
    REP(i,q) id[i] = i;
    query qry({1, 0, id});
    queue<query> que;
    que.push(qry);

    int t = 0;
    while (!que.empty()){
        query qry = que.front();
        que.pop();

        if (qry.ok - qry.ng == 1){
            for (int i : qry.id) ans[i] = qry.ok;
            continue;
        }

        int mi = (qry.ok + qry.ng) / 2;
        if (t > mi){
            // initialize
            t = 0;
        }
        while (t < mi){
            // add t
            t++;
        }

        VI former, latter;
        for (int i : qry.id){
            // check
            if (true) former.push_back(i);
            else latter.push_back(i);
        }

        if (!former.empty()) que.push(query({mi, qry.ng, former}));
        if (!latter.empty()) que.push(query({qry.ok, mi, latter}));
    }
}