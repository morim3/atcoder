#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<int> G[100009];

pair<int, int> farthest_node(int node, int pre){
    pair<int, int> ret(0, node);

    for(auto e: G[node]){
        if(e != pre){
            auto cost = farthest_node(e, node);
            cost.first += 1;
            ret = max(ret, cost);
        }
    }
    return ret;

}

int graph_diameter(){

    auto ret = farthest_node(0, -1);
    ret = farthest_node(ret.second, -1);
    return ret.first+1;
    
}

int main(){
    cin >> N;
    int A, B;
    for(int i = 0; i<N-1; i++){
        cin >> A >> B;
        G[A-1].push_back(B-1);
        G[B-1].push_back(A-1);
    }
    cout << graph_diameter() << endl;;

    
}