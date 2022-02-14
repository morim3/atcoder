#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll=unsigned long long;

int N, M;
ll A[100][100];
ll ans;


ll bfs(ll state, ll prev, ll temp){
    if (state == 0){
        ans = max(temp, ans);
        return temp;
    }
    if (prev == 100){
        ll temp_state = state;
        int index = 0;
        while(temp_state >> 1){
            bfs(state ^ 1<<index, index, temp);
            index++;

        }
    }else{
        for(int next=0; next<array.size(); next++){
        auto copy = array;
        auto next_a = array[next];
        if(next_a > prev){
            copy.erase(copy.begin()+next);
            bfs(copy, 100, temp^A[prev][next_a]);
        }

    }

    }
}
int main(){
    ans = 0;
    cin >> N;

    for(int i=1;i<=2*N-1;i++){
        for(int j=i+1;j<=2*N;j++){
            cin >> A[i][j];
        }
    }
    vector<int> indexes;
    for(int i=0; i<2*N;i++){
        indexes.push_back(i+1);
    }


    bfs(indexes, 100, 0);

    cout << ans << endl;

}
    