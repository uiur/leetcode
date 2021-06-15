// Runtime: 4 ms, faster than 65.27% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 12.1 MB, less than 77.69% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        int depth = 0;
        vector<TreeNode*> current {root};

        while (current.size() > 0) {
            result.push_back(vector<int>());
            vector<TreeNode*> next;

            for (int i = depth % 2 == 0 ? 0 : current.size() - 1; i >= 0 && i < current.size(); i += depth % 2 == 0 ? 1 : -1) {
                result[depth].push_back(current[i]->val);
            }
            for (int i = 0; i < current.size(); i++) {
                if (current[i]->left) next.push_back(current[i]->left);
                if (current[i]->right) next.push_back(current[i]->right);
            }

            current = next;
            depth++;
        }
        return result;
    }
};
