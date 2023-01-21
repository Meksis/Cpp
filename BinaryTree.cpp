#include <iostream>
using namespace std;

// Определим узел бинарного дерева.
struct Node {
  int data;
  Node* left;
  Node* right;
};


template<class Type>
class Tree{
  public:
    Type get_new_node(int data) {
      Type newNode = new Node();
      newNode->data = data;
      newNode->left = newNode->right = NULL;
      return newNode;
    }
    
    // Функция добавления узла в дерево или замены имеющихся значений на новые
    void insert(Type* root, int data) {
      Type newNode = get_new_node(data);
      if (*root == NULL)
        *root = newNode;
      else if (data <= (*root)->data)
        insert(&(*root)->left, data);
      else
        insert(&(*root)->right, data);
    }
    
    
    // Прямой обход дерева (в возрастающем порядке)
    void inorder(Type root) {
      if (root == NULL)
        return;
      inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
    }
    
    
    // Функция для осуществления замены значения дерева
    void replaceValue(Type root, int oldVal, int newVal) {
        if(root == NULL) return;
        if(root->data == oldVal) {
            root->data = newVal;
        }
        replaceValue(root->left, oldVal, newVal);
        replaceValue(root->right, oldVal, newVal);
    }
    
    
};








int main() {
    Tree<Node*> binary_tree;
    
    Node* root = NULL; // Создадим корень дерева 
    
    binary_tree.insert(&root, 150); // Заполним ветки дерева значениями
    binary_tree.insert(&root, 12);
    binary_tree.insert(&root, 1121);
    binary_tree.insert(&root, 1145);
    binary_tree.insert(&root, 474);
    binary_tree.insert(&root, 1410);
    binary_tree.insert(&root, 1197);
    binary_tree.insert(&root, 857);
    binary_tree.insert(&root, 1373);
    binary_tree.insert(&root, 328);
    binary_tree.insert(&root, 858);
    binary_tree.insert(&root, 214);
  
    binary_tree.replaceValue(root, 12, 200); // Заменяем число 12 на 200
    
    binary_tree.inorder(root); // Выводим дерево в порядке возрастания элементов ( Кроме 200, поскольку это - замененное число 12 )
    
    
    return 0;
}
