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
    TreeNode* f(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& result) {
        if(root == NULL)
            return NULL;
        
        root->left  = f(root->left, st, result);
        root->right = f(root->right, st, result);
        
        if(st.find(root->val) != st.end()) { 
            if(root->left != NULL)
                result.push_back(root->left);
            
            if(root->right != NULL)
                result.push_back(root->right);
            
            return NULL;
        } else {
            return root;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        
        unordered_set<int> st;
        
        for(int &num : to_delete) {
            st.insert(num);
        }
        
        f(root, st, result); 
        
        //So, check here if root is to be deleted or not
        if(st.find(root->val) == st.end()) {
            result.push_back(root);
        }
        
        
        return result;
    }
};