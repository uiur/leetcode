#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// Runtime: 4 ms, faster than 72.55% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 11.2 MB, less than 25.47% of C++ online submissions for Search in Rotated Sorted Array.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int pivot = (left + right) / 2;
            if (nums[pivot] > nums[right]) {
                left = pivot + 1;
            } else {
                right = pivot;
            }
        }

        int pivot = left;

        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int i = (l + r) / 2;
            int i2 = (pivot + i) % nums.size();
            if (nums[i2] == target) {
                return i2;
            }
            if (nums[i2] > target) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return -1;
    }
};

int main() {
  auto s = Solution();
  vector<int>v = {3,1};
  cout << s.search(v, 1) << endl;
}
