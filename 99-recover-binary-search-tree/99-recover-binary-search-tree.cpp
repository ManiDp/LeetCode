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
    void recoverTree(TreeNode* root) {
        
        vector<int>res;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int n= q.size();
            
            for(int i=0;i<n;++i){
                
                TreeNode* cur = q.front();
                
                res.push_back(cur->val);
                
                if(cur->left) q.push(cur->left);
                
                if(cur->right) q.push(cur->right);
                
                q.pop();
            }
        }
        
        sort(res.begin(),res.end());
        
        stack<TreeNode*>st;
        
        // st.push(root);
        
        int n= res.size(),i = 0;
        
        TreeNode* cur = root;
        
        while(cur) st.push(cur),cur= cur->left;
        
        while(!st.empty()){
            
            
           TreeNode* cur = st.top();
            st.pop();
            
            cur->val = res[i++];
            
            
            if(cur->right){
                
                st.push(cur->right);
                
                TreeNode* ans = cur->right;
                
                while(ans->left) ans= ans->left,st.push(ans);
            } 
        }
    }
};