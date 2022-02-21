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

ll dir[8][2] = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, -1}, {-1, -2}};
signed main(){
    ll x1 = in();
    ll y1 = in();
    ll x2 = in();
    ll y2 = in();

    REP(i, 8){
        REP(j, 8){
            if(x1 + dir[i][0] + dir[j][0] == x2 && y1 + dir[i][1] + dir[j][1] == y2){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}