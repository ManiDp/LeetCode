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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* cur=root,*temp = root;
        
        int a = 0;
        
        while(cur){
            
            temp = cur;
            
            if(cur->val < val ){
                cur = cur->right;
                
                a=1;
            }else{
                cur = cur->left;
                a=2;
            }
        }
        
        if(a == 1){
            TreeNode* k = new TreeNode(val);
            
            temp->right = k;
        }else{
            
            TreeNode* k = new TreeNode(val);
            
            if(a == 0) return k;
            
            temp->left = k;
        }
        return root;
    }
};