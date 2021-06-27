class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        vector<int> l = inorderTraversal(root->left);
        result.insert(result.end(), l.begin(), l.end());

        result.push_back(root->val);

        vector<int> r = inorderTraversal(root->right);
        result.insert(result.end(), r.begin(), r.end());

        return result;
    }
};
