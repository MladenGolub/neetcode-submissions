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

    void postorder(TreeNode* root, vector<int>& traversal) {
        if(!root) return;
        
        postorder(root->left, traversal);
        postorder(root->right, traversal);
        traversal.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ret;

        postorder(root, ret);

        return ret;

    }
};