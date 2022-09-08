/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void track_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            
            if(cur->left){
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode* , TreeNode*>parent;
        track_parent(root,parent);
        
        unordered_map<TreeNode*,bool>visited;
        
        queue<TreeNode*>q;
        
        visited[target] = true;
        
        int count = 0;
        
        q.push(target);
        
        while(!q.empty()){
            
            TreeNode *cur = q.front();
            
            if(count++ == k) break;
            
            int n= q.size();
            
            for(int i=0;i<n;++i){
                TreeNode *cur=q.front();
                q.pop();
                
                if(cur->left && !visited[cur->left]){
                    q.push(cur->left);
                    visited[cur->left]=true;
                }
                
                if(cur->right && !visited[cur->right]){
                    q.push(cur->right);
                    visited[cur->right]=true;
                }
                
                if(parent[cur] && !visited[parent[cur] ]){
                    q.push(parent[cur]);
                    visited[parent[cur]]=true;
                }
            }
        }
        
        vector<int>res;
        
        int n = q.size();
            
        for(int i=0;i<n;++i){
            TreeNode *cur = q.front();
            q.pop();
            res.push_back(cur->val);
        }
        
        return res;
    }
};