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

const int INF = 1e9;

struct Trie_bit{
    vector<array<int, 2> > trie_nodes = {{0,0}};
    vector<int> mi;
    void push_trie(int x){
        int node = 0;
        FORR(bit,17,0){
            int b = !!(x & (1<<bit));
            if (!trie_nodes[node][b]){
                trie_nodes[node][b] = trie_nodes.size();
                trie_nodes.push_back({0, 0});
                mi.push_back(INF);
            }
            node = trie_nodes[node][b];
            mi[node] = min(mi[node], x);
        }
    }

    int maxmatch(int x, int ma){
        int node = 0;
        int r = 0;
        FORR(bit,17,0){
            int b = !!!(x & (1<<bit));
            if (!trie_nodes[node][b] || mi[trie_nodes[node][b]] >= ma){
                b ^= 1;
            }
            node = trie_nodes[node][b];
            r |= (1 << bit) * b;
        }
        return r;
    }
};
