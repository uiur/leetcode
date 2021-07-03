class Solution {
public:
    int search(vector<int>& nums, int i, int j) {
        if (i == j) return i;
        int m = ((i + j) / 2) + 1;
        int left_peak = search(nums, i, m - 1);
        if (left_peak < m - 1) return left_peak;
        if (nums[left_peak] > nums[m]) return left_peak;
        
        int right_peak = search(nums, m, j);
        return right_peak;
    }
    
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }
};
