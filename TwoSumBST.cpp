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
 
 void inorder(Node*root,int target,vector<int>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left,target,v);
        v.push_back(root->data);
        inorder(root->right,target,v);
    }
    int isPairPresent(struct Node *root, int target)
    {
      vector<int>v;
      inorder(root,target,v);
      int i = 0;
      int j = v.size()-1;
      
      while(i<j){
          if(v[i]+v[j] == target){
              return 1;
          }
          if(v[i]+v[j] < target){
              i++;
          }
          if(v[i]+v[j] > target){
             j--;
          }
          
      }
      return 0;
    }