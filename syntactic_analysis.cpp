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
#include <cctype>
#include <algorithm>
using namespace std;
  
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi M_PI
  
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef string::const_iterator State;
 
int expression(State&);
int term(State&);
int factor(State&);
int number(State&);
 
int expression(State &begin){
    int ret = term(begin);
    while (1){
        if (*begin == '+'){
            begin++;
            ret += term(begin);
        }else if (*begin == '-'){
            begin++;
            ret -= term(begin);
        }else{
            break;
        }
    }
    return ret;
}
 
int term(State &begin){
    int ret = factor(begin);
    while (1){
        if (*begin == '*'){
            begin++;
            ret *= factor(begin);
        }else if (*begin == '/'){
            begin++;
            ret /= factor(begin);
        }else{
            break;
        }
    }
    return ret;
}
 
int factor(State &begin){
    if (*begin == '('){
        begin++;
        int ret = expression(begin);
        begin++;
        return ret;
    }else{
        return number(begin);
    }
}
 
int number(State &begin){
    int ret = 0;
    while (isdigit(*begin)){
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }
    return ret;
}
 
int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--){
        string s;
        getline(cin,s);
        State begin = s.begin();
        int ans = expression(begin);
        cout << ans << endl;
    }
 
    return 0;
}