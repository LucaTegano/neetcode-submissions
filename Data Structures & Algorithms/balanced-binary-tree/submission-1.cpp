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
    // Public function to check if the tree is balanced.
    // It calls the helper DFS function and checks if the returned value is not -1.
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

private:
    // Helper DFS function:
    // Returns the height of the subtree rooted at 'curr' if it's balanced.
    // Returns -1 if the subtree is NOT balanced.
    int dfs(TreeNode* curr) {
        // Base case: An empty tree is balanced and has a height of 0.
        if (!curr) {
            return 0;
        }

        // Recursively get the height (or -1 if unbalanced) of the left subtree.
        int left_height = dfs(curr->left);
        // Recursively get the height (or -1 if unbalanced) of the right subtree.
        int right_height = dfs(curr->right);

        // If either the left or right subtree is unbalanced (returned -1),
        // then the entire tree rooted at 'curr' is also unbalanced.
        if (left_height == -1 || right_height == -1) {
            return -1;
        }

        // Check if the current node's children heights satisfy the balance condition:
        // The absolute difference between left and right subtree heights must be at most 1.
        if (abs(left_height - right_height) > 1) {
            return -1; // The subtree rooted at 'curr' is unbalanced.
        }

        // If all conditions pass, the subtree rooted at 'curr' is balanced.
        // Its height is 1 (for the current node) + the maximum height of its children.
        return 1 + max(left_height, right_height);
    }
};
