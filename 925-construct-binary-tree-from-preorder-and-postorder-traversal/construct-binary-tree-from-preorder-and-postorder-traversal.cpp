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
public:
    TreeNode* f(vector<int>&preorder,vector<int>&postorder,int&preIndex,int start,int end,int n,unordered_map<int,int>&postpos)
    {
        if(preIndex>=n || start>end) return NULL;

        int element=preorder[preIndex++];
        TreeNode* root=new TreeNode(element);

        if (start == end) return root;

        int nextpos=postpos[preorder[preIndex]];

        root->left=f(preorder,postorder,preIndex,start,nextpos,n,postpos);

        root->right=f(preorder,postorder,preIndex,nextpos+1,end-1,n,postpos);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();

        unordered_map<int,int> postpos;

        for(int i=0;i<n;i++){
            postpos[postorder[i]]=i;
        }


        int preIndex=0;

        return f(preorder,postorder,preIndex,0,n-1,n,postpos);
    }
};