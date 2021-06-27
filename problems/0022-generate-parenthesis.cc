#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    map<int, vector<string>> memo = {
      { 1, vector<string> { "()" } }
    };

    vector<string> generateParenthesis(int n) {
      if (memo.find(n) != memo.end()) return memo[n];

      set<string> result_set;
      for (auto s : generateParenthesis(n - 1)) {
        result_set.insert("(" + s + ")");
      }

      for (int i = 1; i < n; i++) {
        for (string s1 : generateParenthesis(n - i)) {
          for (string s2 : generateParenthesis(i)) {
            result_set.insert(s1 + s2);
            result_set.insert(s2 + s1);
          }
        }
      }

      vector<string> result;
      for (auto s : result_set) {
        result.push_back(s);
      }

      memo[n] = result;

      return result;
    }
};

// Runtime: 4 ms, faster than 77.23% of C++ online submissions for Generate Parentheses.
// Memory Usage: 9.2 MB, less than 90.94% of C++ online submissions for Generate Parentheses.
