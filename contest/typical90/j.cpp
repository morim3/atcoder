#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;
const int mod = 1000000007; //10**9+7

template <class T=int>
T in(){ T x; cin >> x; return (x);}



signed main(){
    int N = in();
    vector<int> cum_1;
    vector<int> cum_2;

    cum_1.push_back(0);
    cum_2.push_back(0);

    REP(i, N){
        int C=in(); int P=in();
        if(C == 1){
            cum_1.push_back(P+cum_1[i]);
            cum_2.push_back(cum_2[i]);
        }else{
            cum_2.push_back(P+cum_2[i]);
            cum_1.push_back(cum_1[i]);

        }
        
    }
    
    int M = in();
    vector<int> Ls, Rs;
    REP(i, M){
        Ls.push_back(in()); Rs.push_back(in());
    }

    REP(i, M){
        int L = Ls[i]; int R = Rs[i];
        cout << cum_1[R] - cum_1[L-1] << " " << cum_2[R] - cum_2[L-1] << "\n";
    }
}