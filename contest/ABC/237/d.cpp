#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;

#define pb push_back
#define ALL(x) x.begin(),x.end() 

const int mod = 1000000007; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf

template <class T=int>
T in(){ T x; cin >> x; return (x);}


class Node {
  public:
    int key;
    Node *prev;
    Node *next;
};

signed main(){
    int N = in();
    Node* n = new Node;
    n->key = 0;
    n->prev = nullptr;
    n->next = nullptr;

    Node* current_node = n;

    REP(i, N){
        char s = in<char>();
        Node* new_node = new Node;
        new_node->key = i+1;
        new_node->prev = nullptr;
        new_node->next = nullptr;
        if(s == 'L'){

            if(current_node->prev != nullptr){
                current_node -> prev -> next = new_node;
                new_node -> prev = current_node -> prev;
            }

            current_node->prev = new_node;
            new_node->next = current_node;
            current_node = new_node;

        }else{
            
            if(current_node->next != nullptr){
                current_node -> next -> prev = new_node;
                new_node -> next = current_node -> next;
            }

            current_node->next = new_node;
            new_node->prev = current_node;
            current_node = new_node;

        }

    }

    while(current_node -> prev != nullptr){
        current_node = current_node -> prev;
    }

    REP(i, N+1){
        cout << current_node->key;
        current_node = current_node->next;
        if(i != N){
            cout << " ";
        }
    }
    cout << endl;
    
}