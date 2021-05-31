// Runtime: 980 ms, faster than 5.10% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 13.6 MB, less than 66.20% of C++ online submissions for Remove Duplicates from Sorted Array.
#include<vector>
#include<string>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int i = 0;
      while (i + 1 < nums.size()) {
        if (nums[i] == nums[i + 1]) {
          for (int j = i + 1; j + 1 < nums.size(); j++) {
            nums[j] = nums[j + 1];
          }
          nums.pop_back();
        } else {
          i++;
        }
      }
      return nums.size();
    }
};

int main() {
  Solution s = Solution();
  vector<int> v = {1,1,2,3,4};
  vector<int> v2 = {1,1,1,1,1};
  cout << s.removeDuplicates(v) << endl;
  cout << s.removeDuplicates(v2) << endl;

}
