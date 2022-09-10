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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        
        int n= preorder.size();
        
        for(int i=0;i<n;++i){
            m[inorder[i]] = i;
        }
        
        TreeNode *root = build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        
        return root;
    }
    
    TreeNode *build(vector<int>& preorder, int prestart, int prend,
                    vector<int>& inorder,int instart,int inend,map<int,int>&m){
        
        if(prestart > prend || instart > inend) return NULL;
        
        TreeNode *root = new TreeNode(preorder[prestart]);
        
        int inroot = m[root->val];
        
        int numsleft = inroot - instart;
        
        root->left = build(preorder,prestart+1,prestart+numsleft,
                           inorder,instart,inroot-1,m);
        
        root->right = build(preorder,prestart+numsleft+1,prend,
                            inorder,inroot+1,inend,m);
        
        return root;
        
        
    }
};