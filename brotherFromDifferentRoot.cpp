
   void getinorder(Node* root , vector<int> &v){
        if(root==NULL) return ; 
        
        
        getinorder(root->left , v) ; 
        v.push_back(root->data) ; 
        getinorder(root->right , v) ; 
        
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int> first ; 
        vector<int> second ;
        getinorder(root1 , first) ; 
        getinorder(root2 , second) ;  
          int i = 0 ; 
        int j = second.size() -1 ; 
        int ans = 0 ; 
        while(i<first.size() and j>=0){
            int sum =0 ; 
            if(first[i] + second[j]==x){
                ans++;
                i++;
                j--;
            }
            else if(first[i]+ second[j]>x){
                j--; 
            }
            else if(first[i] + second[j] <x){
                i++;
            }
        }
        return ans ; 
    

    }
