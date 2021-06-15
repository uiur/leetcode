// Runtime: 4 ms, faster than 93.71% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 18.9 MB, less than 12.61% of C++ online submissions for Maximum Depth of Binary Tree.

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
    int traverse(TreeNode* t, int depth) {
        if (t == nullptr) return depth;

        int left_depth = traverse(t->left, depth + 1);
        int right_depth = traverse(t->right, depth + 1);
        return max(left_depth, right_depth);
    }

    int maxDepth(TreeNode* root) {
        return traverse(root, 0);
    }
};
