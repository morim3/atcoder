#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;
const int mod = 1000000007; //10**9+7

#define int ll

template <class T=int>
T in(){ T x; cin >> x; return (x);}


signed main(){
    
    int N = in(); int L = in(); int W = in();
    vector<int> a;
    REP(i, N){
        a.push_back(in());
    }

    sort(a.begin(), a.end());

    int ans = 0;
    int pos = 0;
    int i = 0;

    while(1){
        if(i < N){
            if(a[i] > pos){
                int temp = ceil((double)(a[i]-pos)/(double)W);
                ans += temp;
                pos = pos + temp * W;

            }else{
                pos = a[i] + W;
                i++;
                while(i<N && a[i]<pos){
                    pos = a[i] + W;
                    i++;
                }

            }
        }else{
            ans += ceil((long double)(L-pos)/(long double)W);
            break;

        }
    }
    
    cout << ans << endl;
}