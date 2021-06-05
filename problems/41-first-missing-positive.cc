#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// Runtime: 100 ms, faster than 45.20% of C++ online submissions for First Missing Positive.
// Memory Usage: 66.1 MB, less than 30.82% of C++ online submissions for First Missing Positive.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      nums.push_back(0);
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        if (nums[i] < 0 || nums[i] >= n) {
          nums[i] = 0;
        }
      }

      for (int i = 0; i < n; i++) {
        nums[nums[i] % n] += n;
      }

      for (int i = 1; i < n; i++) {
        if (nums[i] / n == 0) {
          return i;
        }
      }

      return n;
    }
};
