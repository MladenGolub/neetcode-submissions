/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {

    Node* pravi(int n, int r, int c, vector<vector<int>>& grid) {
        
        if(n == 1) {
            return new Node(grid[r][c] == 1, true);
        }

        int mid = n / 2;
        Node* topLeft = pravi(mid, r, c, grid);
        Node* topRight = pravi(mid, r, c + mid, grid);
        Node* bottomLeft = pravi(mid, r+mid, c, grid);
        Node* bottomRight = pravi(mid, r + mid, c + mid, grid);
        if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf) {
            if(topLeft->val == true && topRight->val == true && bottomRight->val == true && bottomLeft->val == true) {
                delete topLeft;
                delete topRight;
                delete bottomLeft;
                delete bottomRight;
                return new Node(true, true);
            } else if(topLeft->val == false && topRight->val == false && bottomRight->val == false && bottomLeft->val == false) {
                delete topLeft;
                delete topRight;
                delete bottomLeft;
                delete bottomRight;
                return new Node(false, true);
            }    
        }
        
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);

    }

public:
    Node* construct(vector<vector<int>>& grid) {
        
        return pravi(grid.size(), 0, 0, grid);

    }
};