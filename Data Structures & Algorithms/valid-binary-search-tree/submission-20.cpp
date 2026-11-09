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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        int min = INT_MIN;
        int max = INT_MAX;

        bool levi = dfs(root->left, root->val, min);
        bool desni = dfs(root->right, max, root->val);

        return levi && desni;
    }

    bool dfs(TreeNode* curr, int max, int min) {
        if(!curr) return true;
        bool levi = true, desni = true;
        if(curr->val > min && curr->val < max) {
            levi = dfs(curr->left, curr->val, min);
            desni = dfs(curr->right, max, curr->val);
        } else {
            return false;
        }

        return levi && desni;
    }
};
