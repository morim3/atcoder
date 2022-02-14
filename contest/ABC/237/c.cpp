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

    string a = in<string>();
    vector<char> st(a.begin(), a.end());

    int ans = 0;
    int i = 0;
    int j = st.size() - 1;
    bool flag = true;
    while(i<j){
        if(st[i] != st[j] ){
            if(st[j] == 'a' && flag){
                j--;
            }else{
                cout << "No" << endl;
                return 0;
            }
        }else if(st[i] != 'a'){
            flag = false;
            i++; 
            j--;
        }else{
            i++; j--;
        }

    }

    cout << "Yes" << endl;
    
}