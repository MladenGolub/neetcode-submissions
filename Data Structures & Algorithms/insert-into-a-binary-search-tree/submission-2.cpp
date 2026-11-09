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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root) {
            return new TreeNode(val);
        }

        TreeNode* cur = root;
        TreeNode* prev = nullptr;

        while(cur != nullptr) {
            if(cur->val > val) {
                prev = cur;
                cur = cur->left;
            } else {
                prev = cur;
                cur = cur->right;
            }
        }
        TreeNode* novi = new TreeNode(val);
        if(prev->val > val) {
            prev->left = novi;
        } else {
            prev->right = novi;
        }

        return root;

    }
};