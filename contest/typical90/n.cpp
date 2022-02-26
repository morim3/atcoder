#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i=0; i<(n); ++i)
#define RANGE(i, s, e) for(ll i=(s); i<(e); ++i)


#define pb push_back
#define ALL(x) x.begin(),x.end() 

const ll mod = 1000000007; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf

template <class T=ll>
T in(){ T x; cin >> x; return (x);}


signed main(){
    ll N=in();
    vector<ll> A;
    vector<ll> B;
    REP(i, N){
        A.pb(in());
        B.pb(in());
    }                        
    sort(ALL(A));
    sort(ALL(B));

    ll ans = 0;
    REP(i, N){
        ans += abs(A[i] - B[i]);
    }
    cout << ans << endl;
}