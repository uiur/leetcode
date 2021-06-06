#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// Runtime: 52 ms, faster than 24.01% of C++ online submissions for Group Anagrams.
// Memory Usage: 20.5 MB, less than 53.19% of C++ online submissions for Group Anagrams.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> m;
      for (auto str: strs) {
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());

        m[sorted_str].push_back(str);
      }

      vector<vector<string>> result;
      for (auto p: m) {
        result.push_back(p.second);
      }

      return result;
    }
};

int main() {
  auto s = Solution();
  vector<string> v = { "tea", "aet", "a"};
  auto result = s.groupAnagrams(v);
  for (auto group: result) {
    for (auto s: group) {
      cout << s << endl;
    }
  }
}
