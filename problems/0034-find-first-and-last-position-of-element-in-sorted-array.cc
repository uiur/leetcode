#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// Runtime: 8 ms, faster than 65.13% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 13.6 MB, less than 58.63% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        vector<int> result(2);
        result[0] = -1;
        result[1] = -1;
        if (nums.size() == 0) return result;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] != target) {
            return result;
        }

        result[0] = left;

        left = 0;
        right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2 + 1;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        result[1] = right;
        return result;
    }
};
