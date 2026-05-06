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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root) return false;
        if(root && !subRoot) return true;

        bool jednakTrenutnom = false;

        if(root->val == subRoot->val) {
            jednakTrenutnom = isSameTree(root, subRoot);
        } 
    
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) || jednakTrenutnom;

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p == nullptr && q != nullptr) return false;
        if(p != nullptr && q == nullptr) return false; 

        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }

    bool isti(TreeNode* p, TreeNode* q) {
        if(p->val == q->val) return true;
        else return false;
    }
};
