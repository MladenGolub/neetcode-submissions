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
private:

    int cnt = 0;

public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        vector<int> pret;
        pret.push_back(root->val);
        this->cnt++;

        dobar(root->left, pret);
        dobar(root->right, pret);            

        return cnt;
    }

    void dobar(TreeNode* curr, vector<int> prethodnici) {

        if(!curr) return;
        bool veci = false;
        for(int i = 0; i < prethodnici.size(); i++) {
            if(curr->val < prethodnici[i]) {
                veci = true;
            }
        }

        if(veci) {//ako postoji neki u putu do mene veci od mene samo prelazim dalje
            prethodnici.push_back(curr->val);
        } else {
            prethodnici.push_back(curr->val);
            this->cnt++;
        }

        dobar(curr->left, prethodnici);
        dobar(curr->right, prethodnici);

    }
};
