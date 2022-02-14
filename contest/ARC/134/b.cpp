#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;
const int mod = 1000000007; //10**9+7

template <class T=int>
T in(){ T x; cin >> x; return (x);}

signed main(){
    int N = in();
    string S = in<string>();

    int track = N-1;
    vector<bool> used(N);

    vector<char> ans(S.begin(), S.end());
    vector<int> min_ind(N);
    vector<char> min_char(N);

    REP(i, N){
        
        if(track <= i) break;

        int j = track;
        char min_ind = -1;
        char min_val = 126;
        while(j>=i){
            if(ans[j] < min_val){
                min_val = ans[j];
                min_ind = j;
            }
            j--;
        }
        if(min_val == ans[i]) continue;
        
        track = min_ind-1;
        swap(ans[i], ans[min_ind]);

    }

    string p(ans.begin(), ans.end());

    cout << p << endl;
    
}

