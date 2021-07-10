/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool searchAncestors(TreeNode* root, TreeNode* node, vector<TreeNode*> &ancestors) {
        if (root == node) return true;
        if (root == nullptr) return false;
        
        ancestors.push_back(root);
        if (searchAncestors(root->left, node, ancestors)) return true;
        if (searchAncestors(root->right, node, ancestors)) return true;
        ancestors.pop_back();
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_ancestors;
        vector<TreeNode*> q_ancestors;
        searchAncestors(root, p, p_ancestors);
        searchAncestors(root, q, q_ancestors);
        p_ancestors.push_back(p);
        q_ancestors.push_back(q);
        unordered_map<TreeNode*, bool> m;
        for (TreeNode* node : q_ancestors) {
            m[node] = true;
        }
        for (int i = p_ancestors.size() - 1; i >= 0; i--) {
            if (m[p_ancestors[i]]) return p_ancestors[i];
        }
        return root;
    }
};
