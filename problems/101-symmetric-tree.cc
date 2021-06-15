// Runtime: 8 ms, faster than 36.71% of C++ online submissions for Symmetric Tree.
// Memory Usage: 16.4 MB, less than 61.46% of C++ online submissions for Symmetric Tree.

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
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;

        return compare(left->left, right->right) && compare(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }
};
