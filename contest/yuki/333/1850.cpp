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

bool dfs(ll X, ll Y){
    if(X>=Y){
        return true;
    }
    bool flag = false;
    RANGE(i, 2, X/2){
        if(i*(X-i) > X)
            flag = dfs(i*(X-i), Y);
    }
    return flag;

}
signed main(){
    ll t = in();
    REP(i, t){
        ll X = in(), Y = in();
        if(X == 1){
            cout <<"No" << endl;
        }else if(X >= Y){
            cout << "Yes" << endl;
        }else{
            if(dfs(X, Y)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }

    }
    
}