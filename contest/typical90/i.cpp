// TODO

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;
const int mod = 1000000007; //10**9+7

template <class T=int>
T in(){ T x; cin >> x; return (x);}

int N;
vector<pair<double, double>> input;

signed main(){

    cin >> N;

    REP(i, N){
        input.push_back(make_pair(in<double>(), in<double>()));
    }

    
    double ans = 0.;
    REP(i, N){
        vector<double> arg;
        REP(j, N){
            if(i==j) continue;
            arg.push_back(atan2(input[j].first-input[i].first, input[j].second-input[i].second)/M_PI*180);
        }

        sort(arg.begin(), arg.end());
        REP(j, N){
            if (i==j){
                continue;
            }
            auto it = lower_bound(arg.begin(), arg.end(), arg[j]>0?arg[j]-180.:arg[j]+180.);

            double temp;
            double temp2;

            if(it == arg.begin()){
                temp = abs(arg[j]-arg[0]);
                temp2 = abs(arg[j] - arg[N-2]);
                
                
            }else if(it == arg.end()){
                temp = abs(arg[j]-arg[0]);
                temp2 = abs(arg[j] - arg[N-2]);
            }else{
                int index = it - arg.begin();
                if(index == N-2){
                    temp = abs(arg[j]-arg[0]);
                    temp2 = abs(arg[j] - arg[N-2]);
                }else{
                    temp = abs(arg[j]-arg[i-1]);
                    temp2 = abs(arg[j]-arg[i]);
                }
            }

            ans = max(ans, max(temp>180?360-temp:temp, temp2>180?360-temp2:temp2));
            
        }

        
        

    }
    

    cout << ans<< endl;
    
    
}
