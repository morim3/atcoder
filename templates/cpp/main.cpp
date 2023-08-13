#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i=0; i<(n); ++i)
#define FOR(i, j, n) for(ll i=(j); i<(n); ++i)

#include <atcoder/all>

// string to char https://marycore.jp/prog/cpp/convert-string-to-char/

long long powll(long long x, long long n) {
    long long ret = 1; while (n > 0) { if (n & 1) ret *= x;  
        x *= x; n >>= 1; } return ret; }

long long powmod(long long x, long long n, ll mod) {
    long long ret = 1; while (n > 0) { if (n & 1) ret = ret * x % mod;  x = x * x % mod; n >>= 1;} return ret; }

#define pb push_back
#define ALL(x) x.begin(),x.end() 

const ll mod = 1000000007; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf


template <class T=ll>
T in(){ T x; cin >> x; return (x);}


signed main(){

}
