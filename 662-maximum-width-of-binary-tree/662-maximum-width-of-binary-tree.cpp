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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,long long int>>q;
        
       long long int ans=0;
        
        q.push({root,0});
        
        while(!q.empty()){
            
            // auto p= q.front();
            
            long long int l = q.front().second, k=q.size(),first =0,last =0;
            
            for(int i=0;i<k;++i){
                
                TreeNode* temp = q.front().first;
                
                 long long int l2 = q.front().second - l;
                
                q.pop();
                
                if(temp->left != NULL) q.push({temp->left,l2 * 2+1});
                
                if(temp->right != NULL) q.push({temp->right,l2 * 2+2});
                
                if(i==0) first = l2;
                
                if(i == k-1) last = l2;
                
                
            }
            ans = max(ans,last - first +1 );
        }
        return ans;
    }
};