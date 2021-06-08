#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

// Runtime: 108 ms, faster than 20.28% of C++ online submissions for Jump Game.
// Memory Usage: 48.1 MB, less than 33.80% of C++ online submissions for Jump Game.
class Solution {
public:
  bool canJump(vector<int>& nums) {
    int jump = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (jump < 0) return false;
      jump = max(jump, nums[i]);
      jump--;
    }
    return true;
  }
};

int main() {
  auto s = Solution();
  vector<int> nums = {1, 2, 3, 0, 1};
  cout << s.canJump(nums) << endl;
}
