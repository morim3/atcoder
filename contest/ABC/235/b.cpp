#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;
const int mod = 1000000007; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf

template <class T=int>
T in(){ T x; cin >> x; return (x);}


signed main(){
    int N = in();
    int ans = -INF32;
    REP(i, N){
        int temp = in();
        if( temp > ans){
            ans = temp;
        }
        else{
            break;
        }
    }
    cout << ans << endl;

    
}