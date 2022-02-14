#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int A[1000009];


int main(){
    cin >> N;
    for (int i = 0; i<N;i++){
        A[i] = 0;
    }
    for(int i = 0; i<4*N-1; i++){
        int temp;
        cin >> temp;
        A[temp-1] = A[temp-1] + 1;
    }

    for(int i=0;i<N;i++){
        if(A[i]==3){
            cout << i+1 << endl;
            break;
        }
    }
    

    
}