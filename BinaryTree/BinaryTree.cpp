#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    BinaryTree<int>* binaryTree = new BinaryTree<int>();

    if (!binaryTree->addItem(1, 0)) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTree->addItem(2, 1)) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTree->addItem(3, 1)) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTree->addItem(4, 2)) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTree->addItem(6, 4)) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTree->addItem(5, 3)) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTree->addItem(7, 3)) 
    {
        cout << "Error adding new node\n";
    }

    binaryTree->show();
    cout << "\n";

    if (!binaryTree->remove(5)) 
    {
        cout << "Ошибка удаления элемента из бинарного дерева\n";
    }

    binaryTree->show();
    cout << "\n";

    BinaryTree<std::string>* binaryTreeStr = new BinaryTree<std::string>();
    if (!binaryTreeStr->addItem("Егор", "")) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTreeStr->addItem("Влад", "Егор")) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTreeStr->addItem("Дима", "Егор")) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTreeStr->addItem("Юра", "Дима")) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTreeStr->addItem("Алина", "Дима")) 
    {
        cout << "Error adding new node\n";
    }
    
    if (!binaryTreeStr->addItem("Миша", "Влад")) 
    {
        cout << "Error adding new node\n";
    }

    binaryTreeStr -> show();
}