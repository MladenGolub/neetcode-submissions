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
        int maxSum = INT_MIN;
        dfs(root, maxSum);

        return maxSum;

    }
 
    int dfs(TreeNode* root, int& maxSum) {

        if(!root) return 0;

        int levi = dfs(root->left, maxSum);
        int desni = dfs(root->right, maxSum);

        int pomMax = max(levi + desni + root->val, max(root->val, max(levi + root->val, desni + root->val)));

        if(pomMax > maxSum) {
            maxSum = pomMax;
        }

        return max(root->val, max(levi + root->val, desni + root->val));

    }
};
