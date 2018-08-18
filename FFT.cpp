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
typedef vector<double> VD;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

typedef complex<double> Comp;
const double pi = acos(-1.0);

vector<Comp> DFT(vector<Comp> f){
    int n = f.size();
    vector<Comp> ff(n);
    REP(i,n){
        Comp zeta(cos(2 * pi / n * i), sin(2 * pi / n * i));
        REP(j,n){
            ff[i] += f[j] * pow(zeta, j);
        }
    }
    return ff;
}

vector<Comp> inverse_DFT(vector<Comp> ff){
    int n = ff.size();
    vector<Comp> f(n);
    REP(i,n){
        Comp zeta(cos(-2 * pi / n * i), sin(-2 * pi / n * i));
        REP(j,n){
            f[i] += ff[j] * pow(zeta, j);
        }
    }
    return f;
}

vector<Comp> FFT(vector<Comp> f){
    int n = f.size();
    if (n == 1) return f;
    vector<Comp> f0, f1;
    REP(i,n){
        if (i % 2 == 0) f0.push_back(f[i]);
        else f1.push_back(f[i]);
    }
    f0 = FFT(f0);
    f1 = FFT(f1);
    Comp zeta(cos(2 * pi / n), sin(2 * pi / n)), theta(1.0, 0.0);
    REP(i,n){
        f[i] = f0[i % (n/2)] + theta * f1[i % (n/2)];
        theta *= zeta;
    }
    return f;
}

vector<Comp> inverse_FFT(vector<Comp> f){
    int n = f.size();
    if (n == 1) return f;
    vector<Comp> f0, f1;
    REP(i,n){
        if (i % 2 == 0) f0.push_back(f[i]);
        else f1.push_back(f[i]);
    }
    f0 = inverse_FFT(f0);
    f1 = inverse_FFT(f1);
    Comp zeta(cos(-2 * pi / n), sin(-2 * pi / n)), theta(1.0, 0.0);
    REP(i,n){
        f[i] = (f0[i % (n/2)] + theta * f1[i % (n/2)]);
        theta *= zeta;
    }
    return f;
}

VL multiply(VL g, VL h){
    int n = 1;
    while (n < g.size() + h.size() - 1) n *= 2;
    vector<Comp> gc(n), hc(n);
    REP(i,g.size()) gc[i] = Comp(g[i], 0.0);
    REP(i,h.size()) hc[i] = Comp(h[i], 0.0);
    vector<Comp> gg = FFT(gc), hh = FFT(hc);
    vector<Comp> ff(n);
    REP(i,n) ff[i] = gg[i] * hh[i];
    vector<Comp> f = inverse_FFT(ff);
    VL ret(n);
    REP(i,n) ret[i] = round(real(f[i] * (1.0 / n)));
    return ret;
}

int main() {
    int n;
    cin >> n;
    VL a(n+1), b(n+1);
    REP(i,n){
        a[i+1] = in();
        b[i+1] = in();
    }

    VL c = multiply(a, b);

    FOR(i,1,2*n){
        printf("%lld\n", c[i]);
    }

    return 0;
}
