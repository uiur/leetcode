class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        for (int i = 0; i < n; i++) {
            int num = nums[i] % (n+1);
            nums[num] += (n+1);
        }
        for (int i = 0; i <= n; i++) {
            if (nums[i] < (n + 1)) return i;
        }
        return -1;
    }
};
