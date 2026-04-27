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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int mid;
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == preorder[0]) { mid = i; break;}
        }

        vector<int> pom1 = vector<int>(preorder.begin()+1, preorder.begin() + mid + 1);
        vector<int> pom2 = vector<int>(inorder.begin(), inorder.begin() + mid);
        root->left = this->buildTree(pom1, pom2);
        vector<int> pom3 = vector<int>(preorder.begin() + mid + 1, preorder.end());
        vector<int> pom4 = vector<int>(inorder.begin() + mid + 1, inorder.end());
        root->right = this->buildTree(pom3, pom4);

        return root;
    }
};
