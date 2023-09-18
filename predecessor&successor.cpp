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
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        Node* temp = root;
        while(temp)
        {
            if(temp -> data <= key)
                temp = temp -> right;
            else
            {
                suc = temp;
                temp = temp -> left;
            }
        }
        temp = root;
        while(temp)
        {
            if(temp -> data >= key)
                temp = temp -> left;
            else
            {
                pre = temp;
                temp = temp -> right;
            }
        }
    }