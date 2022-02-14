#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;

#define pb push_back

const int mod = 1000000007; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf
#define ALL(x) x.begin(),x.end() 

template <class T=int>
T in(){ T x; 
        cin >> x; 
        return (x);}

bool compare(tuple<int, int, int> a, tuple<int, int, int> b){
    return get<0>(a) < get<0>(b);
}

signed main(){

    int N = in(); int Q = in();
    vector<int> A;
    vector<tuple<int, int, int>> query;

    vector<int> count(Q);
    vector<int> ans(Q);

    REP(i, Q){
        ans[i] = -1;
    }

    REP(i, N){
        A.push_back(in());
    }
    REP(i, Q){
        int temp1=in(); int temp2=in();
        query.pb(make_tuple(temp1, temp2, i));
    }

    sort(query.begin(), query.end(), compare);

    REP(i, N){
        auto iter = lower_bound(ALL(query), make_tuple(A[i], -INF32, -INF32));
        int ind = iter - query.begin();
        if(get<0>(query[ind]) == A[i]){
            count[ind]++;
            if(count[ind] == get<1>(query[ind]) && ans[ind] == -1){
                ans[ind] = i+1;
            }
        }

    }

    vector<int> final_ans(N);
    REP(i, Q){
        final_ans[get<2>(query[i])] = ans[i];
    }
    REP(i, Q){
        cout << final_ans[i] << endl;
    }




    
    
}