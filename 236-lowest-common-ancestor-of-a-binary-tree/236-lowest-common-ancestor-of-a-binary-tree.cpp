/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    public:
        TreeNode* f(TreeNode *root, TreeNode *p, TreeNode *q)
        {

            if (root == NULL || root == p || root == q) return root;

            TreeNode *l = f(root->left, p, q);

            TreeNode *m = f(root->right, p, q);
            
            
            if (l == NULL) return m;
            
            else if (m == NULL) return l;
            
            return root;
        }
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        return f(root, p, q);
    }
};