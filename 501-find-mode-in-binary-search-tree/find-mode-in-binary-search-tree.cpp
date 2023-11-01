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
    unordered_map<int,int> mp;
    void inorder(TreeNode* root,vector<int> &ans){
        if(!root){
            return;
        }
        inorder(root->left,ans);
        mp[root->val]++;
        inorder(root->right,ans);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxfreq=0;
        inorder(root,ans);    //inorder gives sorted answer
        for(auto it:mp){
            if(it.second>maxfreq){
                maxfreq=it.second;
                ans={};
                ans.push_back(it.first);
            }
            else if(it.second==maxfreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};