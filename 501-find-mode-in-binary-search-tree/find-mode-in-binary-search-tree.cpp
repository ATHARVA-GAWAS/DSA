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
    int currNum=0;
    int currStreak=0;
    int maxStreak=0;
    void inorder(TreeNode* root,vector<int> &ans){
        if(!root){
            return;
        }
        inorder(root->left,ans);
        if(root->val == currNum){
            currStreak++;
        }else{
            currNum=root->val;
            currStreak=1;
        }
        if(currStreak>maxStreak){
            ans={};
            maxStreak=currStreak;
        }
        if(currStreak==maxStreak){
            ans.push_back(root->val);
        }
        inorder(root->right,ans);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);    //inorder gives sorted answer
        return ans;
    }
};