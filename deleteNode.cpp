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

// Function to delete a node from BST.
Node* inorderSucc(Node*root){
    Node*curr = root;
    while(curr->left !=NULL){
        curr = curr->left;
    }
    return curr;
}
Node *deleteNode(Node *root, int X) {
    if(root == NULL) return root;
    
    if(X<root->data){
        root->left = deleteNode(root->left,X);
    }
   else if(X>root->data){
        root->right = deleteNode(root->right,X);
    }
    else {
       if(root->left==NULL){ //case 1
           Node*temp = root->right;
           free(root);
           return temp;
       }
       if(root->right==NULL){ //case 2
           Node*temp = root->left;
           free(root);
           return temp;
       }
       //case 3
       Node*temp = inorderSucc(root->right);
       root->data = temp->data;
       root->right = deleteNode(root->right,temp->data);
    }
    return root;
}
