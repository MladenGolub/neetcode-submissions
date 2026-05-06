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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return nullptr;

        bool jaP = root->val == p->val;
        bool jaQ = root->val == q->val;

        if(((jaP || jaQ) && dfs(root->right, p, q)) || ((jaP || jaQ) && dfs(root->left, p, q))) {
            return root;
        }
        if((jaP == false && jaQ == false) && dfs(root->right, p, q) && dfs(root->left, p, q)) {//ako ja nisam ni p ni q, a u obe moje grane se nadju p ili q onda sam ja isto resenje
            return root;
        }
        if(dfs(root->left, p, q) && !dfs(root->right, p, q)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if(!dfs(root->left, p, q) && dfs(root->right, p, q)) {
            return lowestCommonAncestor(root->right, p, q);
        }
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return false;
        
        if(root->val == p->val || root->val == q->val) return true;

        bool levo = dfs(root->left, p, q);
        bool desno = dfs(root->right, p, q);

        return levo || desno;//samo zelim da znam da li mi se u podstablu nalazi p ili q 
    }
};
