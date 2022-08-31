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
    bool f(TreeNode* temp1,TreeNode* temp2){
        
        if(temp1 == NULL || temp2 == NULL) return temp1 == temp2;
        
        if(temp1->val != temp2->val) return false;
       
        return f(temp1->left,temp2->right) &&  f(temp1->right,temp2->left); 
    }
    
    bool isSymmetric(TreeNode* root) {
        
        return root == NULL || f(root->left,root->right);
    }
};