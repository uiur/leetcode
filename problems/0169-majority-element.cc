// Runtime: 12 ms, faster than 96.55% of C++ online submissions for Majority Element.
// Memory Usage: 19.8 MB, less than 8.55% of C++ online submissions for Majority Element.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int num : nums) {
            if (m.find(num) == m.end()) m[num] = 0;
            m[num] += 1;
            if (m[num] > n / 2) return num;
        }
        return -1;
    }
};
