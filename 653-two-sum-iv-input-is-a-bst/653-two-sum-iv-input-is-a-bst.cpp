/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSITiterator {
    
    stack<TreeNode*>mystack;
    
    bool reverse = true;
public:
    
     BSITiterator(TreeNode* root,bool isReverse){
        
        reverse = isReverse;
        
        pushAll(root);
        
        
    }
    
    int next(){
            
        TreeNode* cur = mystack.top();
            
        mystack.pop();
        
        if(reverse) pushAll(cur->right);
        else pushAll(cur->left);

        return cur->val;
    }
    
    private : 
    
    void pushAll(TreeNode* root){
        
        if(reverse == true ){
            
            while(root){
                mystack.push(root);
                
                root = root->left;
            }
        }else if(reverse == false){
            
            while(root){
                mystack.push(root);
                root = root->right;
            }
        }
        return;
    }
};
    class Solution {
    public:
    
        bool findTarget(TreeNode* root, int k) {
        
        if(!root) return false;
            
        BSITiterator l(root,true);  // left,Root,Right
        
        BSITiterator r(root,false); // Right, Root,left
        
        int i = l.next() , j = r.next();
        
        while(i < j){
            
            if(i + j == k) return true;
            
            if(i + j > k){
                
                j = r.next();
                
            }else{
                
                i = l.next();
            }
        }
        
        return false;
    }
};