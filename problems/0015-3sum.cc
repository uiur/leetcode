#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_set>
#include<utility>
#include <algorithm>
using namespace std;
int main() {}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> result = {};
      if (nums.size() < 3) return result;
      unordered_set<int> s;
      map<pair<int, int>, bool> m;

      sort(nums.begin(), nums.end());
      for (auto num : nums) {
        s.insert(num);
      }

      for (int i = 0; i < nums.size() - 2; i++) {
        int first = nums[i];
        for (int j = i + 1; j < nums.size() - 1; j++) {
          int second = nums[j];
          int value = -1 * (first + second);
          if (m.find(make_pair(first, second)) != m.end()) {
            continue;
          }
          if (value < second) {
            break;
          }
          if (value == second && nums[j+1] != value) {
            break;
          }

          if (s.find(value) != s.end()) {
            m[make_pair(first, second)] = true;
            result.push_back(vector<int>{ first, second, value });
          }
        }
      }

      return result;
    }
};

// Runtime: 336 ms, faster than 19.49% of C++ online submissions for 3Sum.
// Memory Usage: 23 MB, less than 30.06% of C++ online submissions for 3Sum.
