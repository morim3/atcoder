#include <iostream>
#include <vector>
using namespace std;
int N, L, K;
vector<int> A(N);
bool lower_bound(int k){
    int cut_num = 0;
    int prev_cut = 0;

    for(int i=0; i<N+1; i++){
        if( A[i] - prev_cut >= k){
            cut_num++;
            prev_cut = A[i];
        }
    }
    if (cut_num >= K+1){
        return true;
    }
    return false;
}

int main(void){
    
    cin >> N >> L;
    cin >> K;

    int j;
    for (int i=0;i<N;i++){
        cin >> j;
        A.push_back(j);
    }
    A.push_back(L);

    int lower = 1;
    int upper = L-1;

    while(upper - lower > 1){
        if (lower_bound((lower + upper) / 2)){
            lower = (lower + upper) / 2;
        }else{
            upper = (lower + upper) / 2;
        }
    }

    cout << lower << endl;
    
}
