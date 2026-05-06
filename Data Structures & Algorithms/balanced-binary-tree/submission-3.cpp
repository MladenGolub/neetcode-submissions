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
    bool isBalanced(TreeNode* root) {
        
        if(!root) return true;

        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        
        int brDesni = dfs(root->right);
        int brLevi = dfs(root->left);

        if(l == false || r == false) return false;

        if(brDesni - brLevi > 1 || brLevi - brDesni > 1) return false;

        return true;

    }

    int dfs(TreeNode* root) {

        if(!root) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        return 1 + max(l, r);

    }
};
