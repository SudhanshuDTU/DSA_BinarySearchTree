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
 class Info {
    public:
        int size;
        int max;
        int min;
        int ans;
        bool isBST;
};
    Info solve(Node*root){
        //base case
        if(root==NULL){
            return {0,INT_MIN,INT_MAX,0,true};
        } //Leaf Node
        if(root->left ==NULL && root->right ==NULL){
             return {1,root->data,root->data,1,true};
        }
        Info leftinfo = solve(root->left);
        Info rightinfo = solve(root->right);
        Info curr;
        curr.size = 1 + leftinfo.size + rightinfo.size;
        
        if(leftinfo.isBST && rightinfo.isBST && (leftinfo.max < root->data) && (rightinfo.min > root->data)){
            
            curr.min = min(leftinfo.min,min(rightinfo.min,root->data));
            curr.max = max(rightinfo.max,max(leftinfo.max,root->data));
            curr.ans = curr.size;
            curr.isBST = true;
            return curr;
        }
        curr.ans = max(leftinfo.ans,rightinfo.ans);
        curr.isBST = false;
        return curr;       
        
    }
    int largestBst(Node *root)
    {
    	Info result = solve(root);
    	return result.ans;
    }