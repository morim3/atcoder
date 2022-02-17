#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef unsigned long long ll;

#define pb push_back
#define ALL(x) x.begin(),x.end() 

const int mod = 998244353; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf

template <class T=ll>
T in(){ T x; cin >> x; return (x);}

ll Pow(ll x, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

ll GetDigit(ll num){
    ll digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

signed main(){

    ll N = in();
    ll keta = GetDigit(N);
    ll sum = 0;
    ll last_sum = 0;

    ll last = 9;
    REP(i, keta-1){
        last_sum += last;
        sum += (((1+last%mod) * (last%mod)) / 2) % mod;
        sum %= mod;
        last = last * 10;
    }

    sum += (((1+N%mod-last_sum%mod) * (N%mod-last_sum%mod)) / 2)%mod;

    sum %= mod;

    cout << sum << endl;

    
    
}