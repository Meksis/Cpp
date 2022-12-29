#include<iostream>
 using namespace std;
 
 class BinaryTree
 {
 
 private:
 
 int data;
 BinaryTree *left;
 BinaryTree *right;
 
 public:
 
 BinaryTree(): data(0), left(NULL), right(NULL) {}
 
 int getData() {
  return data;
 }
 
 void setData(int data) {
  this->data = data;
 }
 
 BinaryTree *getLeft() {
  return left;
 }
 
 void setLeft(BinaryTree *left) {
  this->left = left;
 }
 
 BinaryTree *getRight() {
  return right;
 }
 
 void setRight(BinaryTree *right) {
  this->right = right;
 }
 
 void add(int data) {
  if (data < this->data) {
   if (this->left)
    left->add(data);
   else
    left = new BinaryTree(data);
  } else if (data > this->data) {
   if (this->right)
    right->add(data);
   else
    right = new BinaryTree(data);
  }
 }
 
 void remove(int data) {
  BinaryTree *p = this;
  BinaryTree *parent = NULL;
  
  while(p != NULL && p->data != data) {
   parent = p;
   p = (data < p->data) ? p->left : p->right;
  }
  
  if (p == NULL)
   return; // data not found
  
  if (p->left == NULL && p->right == NULL) {
   // Leaf
   if (parent == NULL)
    this->data = 0; // this is the root node
   else {
    if (parent->left == p)
     parent->left = NULL;
    else 
     parent->right = NULL;
   }
   delete p;
   } 
  else if (p->left != NULL && p->right != NULL){
   // Node with two children
   BinaryTree *successor = p->right;
   while (successor->left != NULL) {
    successor = successor->left;
   }
   p->data = successor->data;
   // recursively remove successor
   p->right->remove(successor->data);
  } 
  else {

BinaryTree *child = (p->left != NULL) ? p->left : p->right;
   if (parent == NULL) {
    this->data = child->data;
    this->left = child->left;
    this->right = child->right;
   } 
   else {
    if (parent->left == p)
     parent->left = child;
    else 
     parent->right = child;
   }
   delete p;
  }
  
 }
 
 void display() {
  if (left)
   left->display();
  cout << data << "\t";
  if (right)
   right->display();
 }
 
 void replace(int oldData, int newData) {
  if(data == oldData) {
   data = newData;
   return;
  }
  if (left) left->replace(oldData, newData);
  if (right) right->replace(oldData, newData);
 }
 
 };
