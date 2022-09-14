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
        
        vector<int>res;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            
            for(int i=0;i<n;++i){
                
                TreeNode* temp = q.front();
                
                res.push_back(temp->val);
                
                q.pop();
                
                if(temp->left) q.push(temp->left);
                
                
                if(temp->right) q.push(temp->right);
                
            }
        }
        
        sort(res.begin(),res.end());
        
        return res[k-1];
    }
};