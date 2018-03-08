#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <array>
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

vector<array<int, 2> > trie_nodes = {{0,0}};

void push_trie(int x){
    int node = 0;
    FORR(bit,30,0){
        int b = !!(x & (1<<bit));
        if (!trie_nodes[node][b]){
            trie_nodes[node][b] = trie_nodes.size();
            trie_nodes.push_back({0, 0});
        }
        node = trie_nodes[node][b];
    }
}

int maxmatch(int x){
    int node = 0;
    int r = 0;
    FORR(bit,30,0){
        int b = !!!(x & (1<<bit));
        if (!trie_nodes[node][b]){
            b ^= 1;
        }
        node = trie_nodes[node][b];
        r |= (1 << bit) * b;
    }
    return r;
}