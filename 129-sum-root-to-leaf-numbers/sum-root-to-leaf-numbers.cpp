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
    int travel(TreeNode* root,int sum){
        if(!root){
            return 0;
        }
        sum=sum*10+root->val;
        if(!root->left && !root->right){
            return sum;
        }
        return travel(root->left,sum)+travel(root->right,sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        
       return travel(root,0);
        
    }
};