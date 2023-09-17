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
int minValue(Node* root) {
    if(root== NULL){
        return -1;
    }
    int mini = INT_MAX;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            Node*temp = q.front();
            q.pop();
            if(temp->data < mini){
                mini = min(mini,temp->data);
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
     return mini;
     
}