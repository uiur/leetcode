// Runtime: 160 ms, faster than 5.12% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 94.4 MB, less than 9.49% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

// Runtime: 1808 ms, faster than 5.12% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 495.6 MB, less than 5.18% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

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
    unordered_map<int, int> inorder_memo;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (preorder.size() == 0) return nullptr;
        if (preorder.size() == 1) {
            return new TreeNode(preorder[0]);
        }

        int root = preorder[0];
        int root_index = inorder_memo[root];

        vector<int> preorder_left;
        vector<int> preorder_right;
        for (int i = 1; i < preorder.size(); i++) {
            int inorder_index = inorder_memo[preorder[i]];
            if (inorder_index < root_index) {
                preorder_left.push_back(preorder[i]);
            } else {
                preorder_right.push_back(preorder[i]);
            }
        }

        TreeNode* node = new TreeNode(root);
        node->left = build(preorder_left, left, root_index - 1);
        node->right = build(preorder_right, root_index + 1, right);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
          inorder_memo[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1);
    }
};
