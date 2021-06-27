class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.size() == 0) return;
        vector<int> nums(nums1.begin(), nums1.end());
        int i = 0;
        int j = 0;
        while (i + j < m + n) {
            if (j == n || (i < m && nums[i] <= nums2[j])) {
                nums1[i+j] = nums[i];
                i++;
            } else {
                nums1[i+j] = nums2[j];
                j++;
            }
        }

    }
};
