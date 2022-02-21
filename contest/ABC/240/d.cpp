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
    ll N = in();
    ll top[N];
    ll rensa[N];
    ll num[N];
    ll a = in();
    top[0] = -1;
    rensa[0] = -1;
    num[0] = 0;
    if(a != 1){
        top[1] = a;
        rensa[1] = 1;
        num[1] = 1;
    }else{
        top[0] = -1;
        rensa[0] = -1;
        num[0] = 0;
    }

    cout << num[1] << endl;

    ll now = 1;
    REP(i, N-1){
        ll a = in();
        if(top[now] == a){
            if(rensa[now] + 1 == a){
                now = now - a + 1;
            }else{
                num[now+1] = num[now] + 1;
                rensa[now+1] = rensa[now] + 1;
                top[now+1] = top[now];
                now++;
            }
        }else{
            num[now+1] = num[now] + 1;
            rensa[now+1] = 1;
            top[now+1] = a;
            now++;
        }


        cout << num[now] << endl;
    }
    
}