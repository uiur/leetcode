#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int diff = INT_MAX;
      sort(nums.begin(), nums.end());

      for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
          int complement = target - nums[i] - nums[j];
          int closest_num = searchClosest(nums, j + 1, nums.size() - 1, complement);
          if (abs(complement - closest_num) < abs(diff)) {
            diff = complement - closest_num;
          }
        }
      }

      return target - diff;
    }

    int searchClosest(vector<int>& nums, int l, int r, int target) {
      int i;
      while (l < r) {
        i = (l + r) / 2;
        if (nums[i] == target) {
          return target;
        }

        if (nums[i] < target) {
          if (i == r) {
            return nums[i];
          }
          if (target <= nums[i+1]) {
            return target - nums[i] < nums[i+1] - target ? nums[i] : nums[i+1];
          }
          l = i + 1;
        } else {
          if (i == l) {
            return nums[i];
          }

          if (nums[i-1] <= target) {
            return nums[i] - target < target - nums[i-1] ? nums[i] : nums[i-1];
          }
          r = i - 1;
        }
      }

      return nums[l];
    }
};

// Runtime: 116 ms, faster than 8.20% of C++ online submissions for 3Sum Closest.
// Memory Usage: 9.8 MB, less than 99.50% of C++ online submissions for 3Sum Closest.
