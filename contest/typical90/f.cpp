#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N, K;
string input;

int main(void){
    
    cin >> N >> K;
    cin >> input;

    string dp[N+9][K+9];
    dp[0][1] = input[0];
    for(int i=1;i<N;i++){
        dp[i][1] = min(string("")+input[i], dp[i-1][1]);
    }

    for(int i=1; i<N;i++){
        for(int j=2; j<=i+1&&j<=K; j++){
            if (i != j){
                dp[i][j] = min(dp[i-1][j-1]+input[i], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j-1]+input[i];
            }
        }
    }
    cout << dp[N-1][K];
    cout << endl;

    
    
}
