#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;
const int mod = 1000000007; //10**9+7

template <class T=int>
T in(){ T x; cin >> x; return (x);}

int pow(int x, int n) {
    int ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

signed main(){

    int a = in();
    int ans = 0;
    REP(i, 3){
        ans += (a/pow(10, i))%10*111;
    }
    cout << ans << endl;

    
    
}