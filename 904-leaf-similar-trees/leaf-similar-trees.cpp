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
    void inorder(TreeNode* root,vector<int> &res){
        if(root==NULL){
            return;
        }
        inorder(root->left,res);
        if(root->left==NULL && root->right==NULL){
            res.push_back(root->val);
        }
        inorder(root->right,res);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        inorder(root1,a);
        inorder(root2,b);
        return a==b;
    }
};