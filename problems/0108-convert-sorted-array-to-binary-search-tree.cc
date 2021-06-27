// Runtime: 12 ms, faster than 74.90% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 21.3 MB, less than 76.92% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
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
    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        if (left == right) return new TreeNode(nums[left]);

        int mid = (right + left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(nums, left, mid - 1);
        node->right = build(nums, mid + 1, right);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};
