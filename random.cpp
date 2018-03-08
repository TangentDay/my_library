#include <random>
#include <time.h>

mt19937 mt((int)time(0));

ll rand(ll x){
	return mt() % x;
}


unsigned long xor128(void){
    static unsigned long x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned long t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}

ll rand(ll x){
    return xor128() % x;
}
ll rand(ll x, ll y){
    return x + (xor128() % (y - x));
}