#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    map<int, string> m = {
      { 2, "abc" },
      { 3, "def" },
      { 4, "ghi" },
      { 5, "jkl" },
      { 6, "mno" },
      { 7, "pqrs" },
      { 8, "tuv" },
      { 9, "wxyz" },
    };

    vector<string> letterCombinations(string digits) {
      if (digits.size() == 0) return vector<string>();

      vector <string> result;
      vector<string> tail_result = letterCombinations(digits.substr(1, digits.size() - 1));
      if (tail_result.size() == 0) {
        tail_result.push_back("");
      }

      int digit = digits[0] - '0';
      string chars = m[digit];
      for (char c : chars) {
        for (int i = 0; i < tail_result.size(); i++) {
          string s = c + tail_result[i];
          result.push_back(s);
        }
      }

      return result;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 6.7 MB, less than 95.11% of C++ online submissions for Letter Combinations of a Phone Number.

int main() {
  vector<string> combinations = Solution().letterCombinations("23");
  for (auto combination : combinations) {
    cout << combination << endl;
  }
  return 0;
}
