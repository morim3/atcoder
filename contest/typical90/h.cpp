#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;

template <class T=int>
T in(){ T x; cin >> x; return (x);}
const int mod = 1000000007;


signed main(){

    int N = in();
    if(N < 7){
        cout << 0 << endl;
        return 0;
    }
    string S = in<string>();
    string T = "atcoder";

    int dp[N+10][9];

    REP(i, N+10){
        REP(j, 9){
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i<=N; i++){
        if(T[0] == S[i-1]){
            dp[i][1] = (dp[i-1][1] + 1) % mod;
        }else{
            dp[i][1] = dp[i-1][1];
        }
    }


    for(int i=2; i<=N; i++){
        for(int j=2; j<=i && j<=7; j++){
            if(T[j-1] == S[i-1]){
                dp[i][j] += dp[i-1][j-1] % mod;
            }
            if(i != j){
                dp[i][j] += dp[i-1][j];
            }
            dp[i][j] %= mod;
        }
    }

    cout << dp[N][7] << "\n";
    return 0;

}