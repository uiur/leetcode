#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// Runtime: 28 ms, faster than 6.64% of C++ online submissions for Permutations.
// Memory Usage: 10.2 MB, less than 5.27% of C++ online submissions for Permutations.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> result;
      if (nums.size() == 1) {
        result.push_back(nums);
        return result;
      }

      for (int i = 0; i < nums.size(); i++) {
        int head = nums[i];
        vector<int> rest(nums.begin(), nums.end());
        rest.erase(rest.begin() + i);

        vector<vector<int>> vs = permute(rest);
        for (int j = 0; j < vs.size(); j++) {
          vector<int> v = vs[j];
          v.push_back(head);
          result.push_back(v);
        }
      }

      return result;
    }
};

int main () {
  auto s = Solution();
  vector<int> v = {1,2,3,4};
  auto result = s.permute(v);
  for(auto e : result) {
    for (auto e2 : e) {
      cout << " " << e2;
    }
    cout << endl;
  }
}
