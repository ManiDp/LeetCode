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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>ump;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int n= q.size();
            
            for(int i=0;i<n;++i){
                
                TreeNode* cur = q.front();
                
                ump[cur->val] = 1;
                
                if(cur->left) q.push(cur->left);
                
                if(cur->right) q.push(cur->right);
                
                q.pop();
            }
        }
        
        q.push(root);
        
        while(!q.empty()){
            
            int n= q.size();
            
            for(int i=0;i<n;++i){
                
                TreeNode* cur = q.front();
                
                ump[cur->val] = 0;
                
                if( ump[k-(cur->val)] ) return true;
                
                ump[cur->val] = 1;

                
                if(cur->left) q.push(cur->left);
                
                if(cur->right) q.push(cur->right);
                
                q.pop();
            }
        }
        return false;
    }
};