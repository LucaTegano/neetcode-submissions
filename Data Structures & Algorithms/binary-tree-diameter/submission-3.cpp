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
        dfs(root);
        return res;
    }
    int dfs(TreeNode*  curr) {
        if (!curr) return 0;

        int L = dfs(curr -> left) , R = dfs(curr -> right);

        res = max(res,L + R);
        return 1 + max(L,R);
    }
private:
    int res = 0;
};
