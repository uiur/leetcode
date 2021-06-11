// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
// Memory Usage: 8.3 MB, less than 65.85% of C++ online submissions for Sort Colors.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero += 1;
            }
            if (nums[i] == 1) {
                one += 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i < zero) {
                nums[i] = 0;
            } else if (i < zero + one) {
                nums[i] = 1;
            } else {
                nums[i] = 2;
            }
        }

    }
};
