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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;

        int res = root->val;

        int maxLeviDesni = dfs(root, res);

        return max(res, maxLeviDesni);
    }

    int dfs(TreeNode* node, int &res) {
        if(!node) return 0;

        int leftMax = dfs(node->left, res);
        int rightMax = dfs(node->right, res);
        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);
        
        res = max(res, node->val + leftMax + rightMax);

        return node->val + max(leftMax, rightMax);
    }
};
