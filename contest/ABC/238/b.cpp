#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;

#define pb push_back
#define ALL(x) x.begin(),x.end() 

const int mod = 1000000007; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf

template <class T=int>
T in(){ T x; cin >> x; return (x);}


signed main(){
    int N = in();
    vector <int> angle;

    int now = 0;
    angle.push_back(0);
    REP(i, N){
        now += in();
        now %= 360;
        angle.push_back(now);
    }

    sort(ALL(angle));

    int max_angle = 360 - angle[N];

    REP(i, N){
        max_angle = max(max_angle, angle[i+1]-angle[i]);
    }

    
    cout << max_angle << endl;

    
}