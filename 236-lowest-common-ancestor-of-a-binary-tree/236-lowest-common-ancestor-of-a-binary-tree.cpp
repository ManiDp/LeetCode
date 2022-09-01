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
    bool f(TreeNode* root,TreeNode* p,vector<TreeNode*>&v){
        
        if(root == NULL) return false;
        
        v.push_back(root);
        
        if(root == p ) return true;
        
        
        if(f(root->left,p,v) || f(root->right,p,v)) return true;
        
        v.pop_back();
        
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1,v2;
        
        f(root,p,v1);

        f(root,q,v2);
        
        TreeNode* temp=NULL;
        
        int i=0;
        
        int k=min(v1.size(),v2.size());
        
        while(i<k){
            if(v1[i] == v2[i]) temp=v1[i];
            i++;
        }
        
        return temp;
    }
};