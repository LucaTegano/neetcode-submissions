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
        diameter = 0;
        depth(root);
        return diameter;
    }

    int depth(TreeNode* node) {
        if (!node) return 0;
        int L = depth(node->left) , R = depth(node->right);
        diameter = max(diameter,L + R);
        return 1 + max(L,R);
    }
private:
    int diameter;
};
