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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int result = 0;//ovako mogu da uradim ako ne zelim da imam "globalnu" promenljivu unutrar klase
        //nego lokalnu unutar fje ali moram da je prosledim

        dfs(root, result);

        return result;
    }

    int dfs(TreeNode* curr, int &result) {
        if(!curr) {
            return 0;
        }

        int left = dfs(curr->left, result);
        int right = dfs(curr->right, result);

        result = max(result, left + right);
        return 1 + max(left, right);
    }

};
