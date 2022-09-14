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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur= root;
        int ans=0;
        vector<int>res;
        
        while(cur){
            
            if(cur->left == NULL){
                res.push_back(cur->val);
                cur = cur->right;
                // if(--k == 0) return cur->val;
                
            }else{
                TreeNode* temp = cur->left;
                
                while(temp->right != NULL && temp->right != cur) temp = temp->right;
                
                if(temp->right  == NULL){
                    
                    temp->right = cur;
                    cur = cur->left;
                    // if(--k == 0) ans = cur ->val;
                    
                }else{
                    temp->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res[k-1];
    }
};