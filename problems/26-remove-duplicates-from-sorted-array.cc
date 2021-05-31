// Runtime: 16 ms, faster than 24.97% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 13.7 MB, less than 23.66% of C++ online submissions for Remove Duplicates from Sorted Array.
#include<vector>
#include<string>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() == 0) return 0;

      int i = 0;
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] < nums[j]) {
          nums[i+1] = nums[j];
          i++;
        }
      }

      return i + 1;
    }
};

int main() {
  Solution s = Solution();
  vector<int> v = {1,1,2,3,4};
    // vector<int> v = {1,1,2,2,2,3,4};
  vector<int> v2 = {1,1,1,1,1};
  cout << s.removeDuplicates(v) << endl;
  cout << s.removeDuplicates(v2) << endl;

}
