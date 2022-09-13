/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL) return "";
        
        queue<TreeNode*>q;
        
        string s="";
        
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            
            for(int i=0;i<n;++i){
                
                TreeNode *temp = q.front();
                
                if(temp == NULL) s +='#';
                else s +=to_string(temp->val);
                
                s +=',';
                
                q.pop();
                    
                if(temp){
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        }
        
        
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data == "") return NULL;
        
        stringstream s(data);
        
        string str;
        
        getline(s,str,',');
        
        TreeNode* root =new TreeNode(stoi(str));
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode* temp =q.front();
            
            q.pop();
            
            getline(s,str,',');
            
            if(str == "#"){
                
                temp -> left = NULL;
                
            }else{
                TreeNode* cur = new TreeNode(stoi(str));
                
                temp->left = cur;
                
                q.push(cur);
            }
            
            getline(s,str,',');
            
            if(str == "#"){
                
                temp -> right = NULL;
                
            }else{
                TreeNode* cur = new TreeNode(stoi(str));
                
                temp->right = cur;
                
                q.push(cur);
            }
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));