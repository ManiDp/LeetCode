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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>todo;
        
        vector<int>ans;
        
        if(root == NULL) return ans;
        
        todo.push(root);
        
        while(!todo.empty()){
            int k=todo.size();
            
            for(int i=0;i<k;++i){
                
                TreeNode* temp=todo.front();
                
                if(temp->left != NULL) todo.push(temp->left);
                
                if(temp->right != NULL) todo.push(temp->right);
                
                if(i == k-1) ans.push_back(temp->val);
                
                todo.pop();
                
            }
        }
        
        return ans;
    }
};