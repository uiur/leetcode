class Solution {
public:
    unordered_map<int, int> m;
    int search(vector<int>& nums, int i) {
        if (m.find(i) != m.end()) return m[i];
        
        int n = nums.size();
        if (i >= n) return 0;
        
        int result = max(nums[i] + search(nums, i + 2), search(nums, i + 1));
        m[i] = result;
        return result;
    }
    
    int rob(vector<int>& nums) {
        return search(nums, 0);
    }
};
