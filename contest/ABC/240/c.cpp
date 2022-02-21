#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i=0; i<(n); ++i)
#define FOR(i, j, n) for(ll i=(j); i<(n); ++i)


#define pb push_back
#define ALL(x) x.begin(),x.end() 

const ll mod = 1000000007; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf

template <class T=ll>
T in(){ T x; cin >> x; return (x);}


signed main(){
    bool now[109][10009];
    ll N=in(), X=in();
    ll a = in(), b = in();
    now[0][a] = true;
    now[0][b] = true;
    REP(i, N-1){
        ll a = in(), b = in();
        REP(j, X){
            if(now[i][j]) 
                now[i+1][j+a] = now[i+1][j+b] = true;
        }
    }

    if(now[N-1][X]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    
}