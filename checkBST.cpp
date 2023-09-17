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
void inorder(Node*root,vector<int>&v){
        //base case
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
         inorder(root->right,v);
    }
    bool isBST(Node* root) 
    {
        vector<int>v;
        inorder(root,v);
        
        for(int i=1;i<v.size();i++){
            if(v[i-1] >= v[i] ){
                return false;
            }
        }
        return true;
    }