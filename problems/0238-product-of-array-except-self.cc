class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> front(n);
        vector<int> back(n);
        vector<int> result(n);
        
        front[0] = nums[0];
        back[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            front[i] = nums[i] * front[i-1];
            
            int j = n - 1 - i;
            back[j] = nums[j] * back[j + 1];
        }
        
        result[0] = back[1];
        result[n - 1] = front[n - 2];
        for (int i = 1; i < n - 1; i++) {
            result[i] = front[i - 1] * back[i + 1];
        }
        
       
        return result;
    }
};
