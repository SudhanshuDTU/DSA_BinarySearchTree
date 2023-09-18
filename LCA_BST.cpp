#include<iostream>
#include<queue>
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

Node* lca(Node* root ,int n1 ,int n2 )
    {
      //base case
      if(root==NULL){
          return NULL;
      }
      //check
      if(root->data == n1 || root->data == n2){
          return root;
      }
      //left and right
      Node* leftAns = lca(root->left,n1,n2);
      Node*rightAns = lca(root->right,n1,n2);
      
      if(leftAns != NULL && rightAns != NULL){
          return root;
      }
      else if(leftAns == NULL && rightAns != NULL){
          return rightAns;
      }
       else if(leftAns != NULL && rightAns == NULL){
          return leftAns;
      }
       else{
          return NULL;
      }
      
      
      
      
    }