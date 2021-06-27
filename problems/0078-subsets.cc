class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = { {} };

        for (int i = 0; i < nums.size(); i++) {
            int n = result.size();
            for (int j = 0; j < n; j++) {
                vector<int> v(result[j].begin(), result[j].end());
                v.push_back(nums[i]);
                result.push_back(v);
            }
        }
        return result;
    }
};
