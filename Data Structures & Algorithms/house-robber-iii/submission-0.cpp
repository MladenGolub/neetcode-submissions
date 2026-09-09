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

    vector<int> dfs(TreeNode* root) {
        //ako napravim fju tako da vraca vector koji ce imati 2 vrednosti na prvom mestu ce biti kolika je suma da se cvor preskoci, a na drugom kolika ce biti da se uzme
        if(!root) return vector<int>(2, 0);

        vector<int> levi = dfs(root->left);
        vector<int> desni = dfs(root->right);

        int maxSuma = *max_element(levi.begin(), levi.end()) + *max_element(desni.begin(), desni.end());
    
        int saCvorom = root->val + levi[0] + desni[0];
    
        vector<int> ret = {maxSuma, saCvorom};
    
        return ret;
    }

public:
    int rob(TreeNode* root) {
        
        vector<int> ret = dfs(root);

        return max(ret[0], ret[1]);

    }
};