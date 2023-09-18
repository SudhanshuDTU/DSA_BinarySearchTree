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
  Node*toBST(vector<int>& nums,int s,int e){
      if(s>e){
          return NULL;
      }
      int mid = (s+e)/2;
      Node*root = new Node(nums[mid]);
      root->left = toBST(nums,s,mid-1);
      root->right = toBST(nums,mid+1,e);
      return root;
  }
  void preorder(Node*root,vector<int>& ans){
      if(root==NULL){
          return;
      }
      ans.push_back(root->data);
      preorder(root->left,ans);
      preorder(root->right,ans);
  }
    vector<int> sortedArrayToBST(vector<int>& nums) {
       vector<int>ans;
       Node*root =  toBST(nums,0,nums.size()-1);
       preorder(root,ans);
       return ans;
    }