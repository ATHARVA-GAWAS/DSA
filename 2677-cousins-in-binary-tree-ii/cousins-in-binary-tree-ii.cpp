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
private:
    void dfs(TreeNode* parent, int level, vector<int>& sum) {
        int leftval = 0;
        int rightval = 0;
        
        if (parent->left != nullptr) leftval = parent->left->val;
        if (parent->right != nullptr) rightval = parent->right->val;

        if (parent->left != nullptr) {
            parent->left->val = sum[level + 1] - leftval - rightval;
            dfs(parent->left, level + 1, sum);
        }

        if (parent->right != nullptr) {
            parent->right->val = sum[level + 1] - leftval - rightval;
            dfs(parent->right, level + 1, sum);
        }
    }

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum;

        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int k = Q.size();
            int s = 0;
            while (k--) {
                auto node = Q.front();
                Q.pop();
                s += node->val;
                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }
            sum.push_back(s);
        }

        root->val = 0;
        dfs(root, 0, sum);
        return root;
    }
};