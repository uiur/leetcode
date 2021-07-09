class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            nums[j] = nums[i];
            j++;
        }
        
        for (; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
