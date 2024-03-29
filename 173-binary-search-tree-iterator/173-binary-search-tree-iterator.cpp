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
class BSTIterator {
public:
    
    stack<TreeNode*>st;
    
    BSTIterator(TreeNode* root) {
        
        pushAll(root);
        
    }
    
    int next() {
        
        TreeNode* cur =  st.top();
        
        st.pop();
        
        pushAll(cur->right);
        
        return cur->val;
    }
    
    bool hasNext() {
        
        return !st.empty();
        
    }
    
    void pushAll(TreeNode* cur){
        
        while(cur){
            
            st.push(cur);
            
            cur = cur->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */