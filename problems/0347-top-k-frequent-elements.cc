bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            count[nums[i]] += 1;
        }
        vector<pair<int, int>> frequencies;
        for (pair<int, int> p : count) {
            frequencies.push_back(p);
        }
        sort(frequencies.begin(), frequencies.end(), compare);
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(frequencies[i].first);
        }
        
        return result;
    }
};
