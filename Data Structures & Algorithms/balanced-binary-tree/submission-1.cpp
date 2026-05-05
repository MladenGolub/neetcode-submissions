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
        if(!root) return true;//ako nemamo nista onda je ispunjen uslov

        bool levi = true;
        bool desni = true;

        levi = levi && isBalanced(root->left);
        desni = desni && isBalanced(root->right);

        int dLevi = dfs(root->left);
        int dDesni = dfs(root->right);

        if(levi == false || desni == false) return false;

        return (dLevi - dDesni > 1 || dLevi - dDesni < -1) ? false : true;
    }

    int dfs(TreeNode* curr) {
        if(!curr) return 0;

        int left = dfs(curr->left);
        int right = dfs(curr->right);

        return 1 + max(left, right);//vracam dubinu ispod cvora
    }
};
