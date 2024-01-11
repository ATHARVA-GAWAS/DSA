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
    int diff=0;
    void solve(TreeNode* root,int minval,int maxval){
        if(!root){
            return;
        }
        diff=max(diff,max(abs(minval-root->val),abs(maxval-root->val)));
        minval=min(minval,root->val);
        maxval=max(maxval,root->val);
        solve(root->left,minval,maxval);
        solve(root->right,minval,maxval);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root){
            return 0;
        }
        int minval=root->val,maxval=root->val;
        solve(root,minval,maxval);
        return diff;
    }
};