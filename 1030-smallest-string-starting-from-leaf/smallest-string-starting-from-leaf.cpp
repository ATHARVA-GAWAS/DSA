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
     string res="";  
    void solve(TreeNode* root, string s) 
    {
        if(!root) 
            return;
        s+='a'+root->val; 
        if(!root->left && !root->right) 
        {
            reverse(begin(s), end(s)); 
            if(res=="")
                res=s; 
            else
                res=min(res,s); 
        }
        solve(root->left, s);  
        solve(root->right, s);  
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root) 
            return "";
        solve(root, ""); 
        return res; 
    }
};