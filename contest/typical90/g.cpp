#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;

ll N;
vector<ll> vec;
ll Q;

int main(){

    cin >> N;
    ll temp;
    for(int i=0; i<N; i++){
    
        cin >> temp;
        vec.push_back(temp);

    }

    sort(vec.begin(), vec.end());

    cin >> Q;
    ll B;

    for(int i=0; i<Q; i++){
        cin >> B;

        if (B >= vec[N-1]){
            cout << B - vec[N-1] << "\n";
            continue;
        }
        if (B <= vec[0]){
            cout << vec[0] - B << "\n";
            continue;
        }
        auto iter_lower = lower_bound(vec.begin(), vec.end(), B);

        ll idx_lower = distance(vec.begin(), iter_lower); 

        cout << min(abs(vec[idx_lower]-B), abs(vec[idx_lower-1]-B)) << "\n";
         
    }
    
    

}