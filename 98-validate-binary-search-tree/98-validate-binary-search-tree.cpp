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
    
    bool isValid(TreeNode* root,long long a,long long b){
        
        if(root == NULL) return true;
        
       if(a >= (root->val)  || (root->val >= b)) return false;
        
        return isValid(root->left,a,root->val) && isValid(root->right,root->val,b);
    }
    bool isValidBST(TreeNode* root) {
        
        return isValid(root,LONG_MIN,LONG_MAX);
        
    }
};