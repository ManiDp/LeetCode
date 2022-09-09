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
class Solution {
public:
    int lefts(TreeNode * root){
        int count = 0;
        while(root){
            count++;
            root = root->left;
        }
        return count;
    }
    
    int rights(TreeNode * root){
        int count = 0;
        while(root){
            count++;
            root = root->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        int l=-1,rl =-2;
        
        if(root == NULL) return 0;
        
         l = lefts(root);
        
         rl = rights(root);
        
        if(l == rl) return pow(2,l)-1;
        
        int p = 0;
        
        if(root){
            p = countNodes(root->left)+countNodes(root->right);
        }
        
        return 1+p;
    }
};