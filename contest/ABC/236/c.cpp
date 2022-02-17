#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
string A[1000009];



int main(){
    cin >> N >> M;
    
    for(int i=0; i<N;i++){
        cin >> A[i];
    }

    int track = 0;

    for(int i=0; i<M;i++){
        string temp;
        cin >> temp;
        while(temp!=A[track]){
            cout << "No ";
            track++;
        }
        if(i!=M-1){
        cout << "Yes ";
        }else{
            cout << "Yes";
        }
        track++;

    }
    
    

    
}