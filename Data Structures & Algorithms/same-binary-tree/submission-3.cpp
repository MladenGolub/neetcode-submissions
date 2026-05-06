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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p == nullptr && q != nullptr) return false;
        if(p != nullptr && q == nullptr) return false; 

        bool jednaki = isti(p, q);
        bool jednakiLevi = isSameTree(p->left, q->left);
        bool jednakiDesni = isSameTree(p->right, q->right);

        return (jednaki && jednakiLevi && jednakiDesni) ? true : false;

    }

    bool isti(TreeNode* p, TreeNode* q) {
        if(p->val == q->val) return true;
        else return false;
    }
};
