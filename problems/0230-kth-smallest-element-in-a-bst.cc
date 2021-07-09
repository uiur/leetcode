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
    int count(TreeNode* node) {
        if (node == nullptr) return 0;
        return count(node->left) + count(node->right) + 1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int left_count = count(root->left);
        if (k <= left_count) return kthSmallest(root->left, k);
        if (k == left_count + 1) return root->val;
        return kthSmallest(root->right, k - left_count - 1);
    }
};
