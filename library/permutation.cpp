#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool used[10000009];
vector<int> current;
vector<int> input;
int n;


void print_permutation(vector<int> vec){
    n = vec.size();
    input = vec;
    for(int i=0; i<n;i++){
        used[i] = false;
    }
    dfs();

}

void dfs(){
    for(int i=0; i<n;i++){
        if(current.size() == n){
            for(auto v: current){
                cout << v << " ";
            }
        }
        if(used[i] == false){
            current.push_back(input[i]); used[i] = true;
            dfs();
            current.pop_back(); used[i] = false;
        }
    }



}