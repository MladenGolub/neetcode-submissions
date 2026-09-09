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

    void inorder(TreeNode* root, vector<int>& traversal) {
        if(!root) return;
        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ret;

        inorder(root, ret);

        return ret;

    }
};