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
    bool isValid(TreeNode* root, int min, int max) {
        if (root->left != nullptr) {
            if (!(root->left->val < root->val && root->left->val >= min)) return false;
            if (!isValid(root->left, min, root->val - 1)) return false;
        }

        if (root->right != nullptr) {
            if (!(root->val < root->right->val && root->right->val <= max)) return false;
            if (!isValid(root->right, root->val + 1, max)) return false;
        }

        return true;

    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};
