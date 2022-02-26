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

void solve(){
    ll N=in(), M=in();
    vector<int> x, y;
    REP(i, N){
        x.pb(in());
        y.pb(in());
    }

    vector<int> fs(N);
    vector<int> A(N);

    fs[0] = 0;
    A[0] = 0;
    for(int i = 1; i<N+1; i++){
        fs[i] = fs[i-1] + x[i-1] * y[i-1];
        A[i] = A[i-1] + fs[i-1] * y[i] + x[i] * ((1+y[i])*y[i] / 2);
    }

    vector<int> fi;

    fi.pb(0);
    REP(i, N){
        fi.push_back(fi[i]+y[i]);
    }

    vector<int> B(N);
    B[0] = 0;
    for(int i = 1; i<=N; i++){
        B[i] = B[i-1] + x[i-1] * (1+y[i-1]) * y[i-1] / 2;
    }

    REP(i, N){
        if(B[i] + x[i] > 0 && B[i+1] < 0){
            ll po = A[i] - x[i] * (B[i] / x[i]);


        }
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;
}


signed main(){
    ll T = in();

    REP(i, T){
        solve();
    }
}