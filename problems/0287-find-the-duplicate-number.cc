class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) count++;
            }
            
            if (count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
