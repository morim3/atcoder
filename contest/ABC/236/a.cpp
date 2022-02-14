#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a, b;


int main(){
    string G;
    cin >> G;
    int A, B;
    cin >> A >> B;
    swap(G[A-1], G[B-1]);
    cout << G << endl;

    
}