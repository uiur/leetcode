// Runtime: 4 ms, faster than 80.21% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 12.6 MB, less than 31.43% of C++ online submissions for Binary Tree Level Order Traversal.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> current {root};
        vector<vector<int>> result;
        if (root == nullptr) return result;

        while (current.size() > 0) {
            vector<int> tmp;
            vector<TreeNode*> next;
            for (int i = 0; i < current.size(); i++) {
                tmp.push_back(current[i]->val);

                if (current[i]->left) next.push_back(current[i]->left);
                if (current[i]->right) next.push_back(current[i]->right);
            }

            result.push_back(tmp);
            current = next;
        }
        return result;


    }
};
