#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i=0; i<(n); ++i)
typedef long long ll;

#define pb push_back
#define ALL(x) x.begin(),x.end() 

const ll mod = 1000000007; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf

template <class T=ll>
T in(){ T x; cin >> x; return (x);}


signed main(){
    vector<tuple<ll, ll, ll>> w;

    ll N = in();
    REP(i, N){
        ll D=in(), C=in(), S=in();
        w.push_back(make_tuple(D, C, S));
    }

    sort(ALL(w), [](tuple<int, int, int> const& iLhs, 
                    tuple<int, int, int> const& iRhs)
        {
            return get<0>(iLhs) < get<0>(iRhs);
        });

    ll dp[N+1][get<0>(w[N-1])+100] = {};
    REP(i, get<0>(w[N-1])+1){
        if(i < get<1>(w[0]) || i > get<0>(w[0])){
            dp[0][i] = 0;
        }else{
            dp[0][i] = get<2>(w[0]);
        }
        
    }

    REP(i, N-1){
        REP(j, get<0>(w[N-1])+1){
            if(j < get<1>(w[i+1]) || j > get<0>(w[i+1])){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], get<2>(w[i+1]) + dp[i][j-get<1>(w[i+1])]);
            }
        }
    }
    ll ans = 0;
    REP(i, get<0>(w[N-1])+1){
        ans = max(ans, dp[N-1][i]);
    }

    cout << ans << endl;
    
}