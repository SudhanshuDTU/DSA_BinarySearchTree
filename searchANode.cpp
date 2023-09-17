#include<iostream>
using namespace std;

class Node{
    public:
   int data;
   Node* left;
   Node* right;
   Node(int d){
      data = d;
      this->left= NULL;
      this->right = NULL;
   }
};

bool search(Node* root, int x) {
   //base case
   if(root==NULL){
       return false;
   }
   if(root->data == x){
       return true;
   }
   if(x > root->data){
      return search(root->right,x);
   }
   if(x < root->data){
  return search(root->left,x);
   }    
 
  