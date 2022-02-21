
template <class T=long long>
class LinkedList {
private:
  class Node {
  public:
    T key;
    Node *prev;
    Node *next;
  };
  
  Node *nil;  // 番兵

  // keyを持つ最初のノードのポインタを返す
  Node* list_search(T key) {
    Node *current = nil->next;
    while (current != nil && current->key != key) {
      current = current->next;
    }
    return current;
  }

  // 引数に与えられたノードを削除
  void delete_node(Node *node) {
    if (node == nil) return;  // nodeが番兵の時は何もしない
    // リンクつなぎ変え
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;  // メモリ解放
  }
  
public:
  LinkedList() {
    nil = new Node;
    nil->prev = nil;
    nil->next = nil;
  }

  // keyを先頭に挿入
  void insert(T key) {
    Node *x;  // 新しいノードをさすポインタ
    x = new Node;
    x->key = key;
    // リンクのつなぎ替え
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
  }  

  // keyを持つ最初のノードを削除
  void delete_key(T key) {
    delete_node(list_search(key));
  }

  // 先頭を削除
  void delete_first() {
    delete_node(nil->next);
  }

  // 末尾を削除
  void delete_last() {
    delete_node(nil->prev);
  }

  // リストの全ての要素を表示
  void print_list() {
    int cnt = 0;
    Node *current = nil->next;
    
    while (current != nil) {
      if (cnt++ > 0) cout << " ";
      cout << current->key;
      current = current->next;
    }
    cout << endl;      
  }
  
};