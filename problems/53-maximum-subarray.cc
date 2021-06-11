// Runtime: 596 ms, faster than 5.03% of C++ online submissions for Maximum Subarray.
// Memory Usage: 13.2 MB, less than 12.05% of C++ online submissions for Maximum Subarray.
// brute force
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int max = nums[0];
//         for (int i = 0; i < nums.size(); i++) {
//             int sum = 0;
//             for (int j = i; j < nums.size(); j++) {
//                 sum += nums[j];
//                 if (sum > max) {
//                     max = sum;
//                 }
//             }
//         }
//         return max;
//     }
// };


// Runtime: 8 ms, faster than 49.86% of C++ online submissions for Maximum Subarray.
// Memory Usage: 13.2 MB, less than 12.05% of C++ online submissions for Maximum Subarray.

// greedy
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int min_sum = 0;
        int res = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            res = max(sum - min_sum, res);
            min_sum = min(min_sum, sum);
        }
        return res;
    }
};
