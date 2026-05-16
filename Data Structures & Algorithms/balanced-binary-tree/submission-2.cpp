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
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
private:
    int dfs(TreeNode* curr) {
        if (!curr) return 0;

        int left_h = dfs(curr -> left);
        int right_h = dfs(curr -> right);

        if (left_h == -1 || right_h == -1) {
            return -1;
        }

        if(abs(left_h - right_h) > 1) {
            return -1;
        }
        return 1 + max(left_h,right_h);
    }
};
