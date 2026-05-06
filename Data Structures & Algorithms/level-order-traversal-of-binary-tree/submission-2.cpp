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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> pom;
            TreeNode* curr;
            while(cnt > 0) {
                curr = q.front();
                q.pop();
                pom.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                cnt--;
            }
            
            res.push_back(pom);
        } 
        return res;
    }
};
