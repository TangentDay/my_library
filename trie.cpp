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
#include <bitset>
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

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

struct Trie {
    vector<array<int, 26> > trie_nodes = {{}};
    vector<int> sz = {0};

    void push(string s){
        int node = 0;
        sz[node]++;
        for (char c : s){
            int x = c - 'a';
            if (!trie_nodes[node][x]){
                trie_nodes[node][x] = trie_nodes.size();
                trie_nodes.push_back({});
                sz.push_back(0);
            }
            node = trie_nodes[node][x];
            sz[node]++;
        }
    }

    int lcp(string s){
        int node = 0, ret = 0;
        for (char c : s){
            int x = c - 'a';
            if (!trie_nodes[node][x]) return ret;
            node = trie_nodes[node][x];
            ret++;
        }
        return ret;
    }

    bool ismatch(string s){
        return lcp(s) == s.length();
    }

    VI cnt(string s){
        int node = 0;
        VI ret;
        for (char c : s){
            int x = c - 'a';
            if (!trie_nodes[node][x]) return ret;
            node = trie_nodes[node][x];
            ret.push_back(sz[node]);
        }
        return ret;
    }
};