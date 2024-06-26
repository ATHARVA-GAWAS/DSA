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
    TreeNode* buildBST(int l,int r,vector<int> &a){
        if(l>r){
            return nullptr;
        }
        int mid=(l+r)/2;
        TreeNode* root1=new TreeNode(a[mid]);
        root1->left = buildBST(l,mid-1,a);
        root1->right = buildBST(mid+1,r,a);
        return root1;
    }
    void inorder(TreeNode* root,vector<int> &a){
        if(!root){
            return;
        }
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        vector<int> a;
        inorder(root,a);
        int l=0,r=a.size()-1;
        
        return buildBST(l,r,a);

    }
};