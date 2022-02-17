#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;

void depth_width(string now, int n, int m){
    if (n < N){
        depth_width(now + "(", n + 1, m);
    }

    if (n > m){
        depth_width(now + ")", n, m+1);
    }

    if (m == N){
        cout << now << endl;
        
    }
    
}

int main(){
    cin >> N;
    if (N % 2 == 1){
        cout << endl;
        return 0;
    }else{
        N = N/2;
    }

    depth_width("", 0, 0);
}