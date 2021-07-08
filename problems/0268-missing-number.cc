class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> found;
        for (int num : nums) {
            found.insert(num);
        }
        for (int i = 0; i <= n; i++) {
            if (found.find(i) == found.end()) return i;
        }
        return -1;
    }
};
