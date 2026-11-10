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
    int rob(TreeNode* root) {
        
        pair<int, int> pom = dfs(root);

        return max(pom.first, pom.second);
    }

    pair<int,int> dfs(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }

        pair<int, int> levi = dfs(root->left);
        pair<int, int> desni = dfs(root->right);

        //u prvi u paru stavljam koja bi bila vrednost da se uzme sam cvor, a u drugi stavljam kad bi se on preskocio
        int maxSuma = max(levi.first + desni.first, max(levi.first + desni.second, max(levi.second + desni. first, levi.second + desni.second)));
        return {root->val + levi.second + desni.second, maxSuma};

    }
};