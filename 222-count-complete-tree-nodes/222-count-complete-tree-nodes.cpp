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
    int f(TreeNode * root){
        if(root == NULL)return 0;
        
        int p = 0,q = 0;
        
        if(root->left) p= 1+f(root->left);
        
        if(root->right) q = 1+f(root->right);
        
        return p+q;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL ) return 0;
        
        return 1+f(root);
    }
};