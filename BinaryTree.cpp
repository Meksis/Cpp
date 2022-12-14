#include <iostream>
using namespace std;

// Определим узел бинарного дерева.
struct Node {
  int data;
  Node* left;
  Node* right;
};

// Функция создания нового узла
Node* getNewNode(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Функция добавления узла в дерево или замены имеющихся значений на новые
void insert(Node** root, int data) {
  Node* newNode = getNewNode(data);
  if (*root == NULL)
    *root = newNode;
  else if (data <= (*root)->data)
    insert(&(*root)->left, data);
  else
    insert(&(*root)->right, data);
}

// Прямой обход дерева (в возрастающем порядке)
void inorder(Node* root) {
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// Функция для осуществления замены значения дерева
void replaceValue(Node *root, int oldVal, int newVal) {
    if(root == NULL) return;
    if(root->data == oldVal) {
        root->data = newVal;
    }
    replaceValue(root->left, oldVal, newVal);
    replaceValue(root->right, oldVal, newVal);
}

int main() {
  Node* root = NULL; // Создадим корень дерева 
  insert(&root, 150); // Добавим данные в дерево
  insert(&root, 10);
  insert(&root, 20);
  insert(&root, 25);
  insert(&root, 8);
  insert(&root, 12);
  replaceValue(root, 12, 200);
  cout << "Прямой обход дерева: ";
  inorder(root);
  cout << endl;
  return 0;
}
