#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    map<char, char> matched_paren = {
      {'(', ')'},
      {'{', '}'},
      {'[', ']'},
    };

    bool isValid(string s) {
      if (s.size() == 0) return true;

      if (isOpen(s[0])) {
        string sub = s.substr(1, s.size() - 1);
        int i = findMatched(sub, matched_paren[s[0]]);
        if (i == sub.size()) return false;
        if (i + 2 < s.size()) {
          return isValid(s.substr(i + 2, s.size() - (i + 2)));
        } else {
          return true;
        }
      }

      return false;
    }

    int findMatched(string s, char c) {
      int i = 0;
      while (i < s.size()) {
        if (isOpen(s[i])) {
          string sub = s.substr(i + 1, s.size() - (i + 1));
          int matched = (i + 1) + findMatched(sub, matched_paren[s[i]]);
          if (matched == s.size()) return s.size();
          i = matched + 1;
        } else {
          if (s[i] == c) {
            return i;
          } else {
            return s.size();
          }
        }
      }

      return i;
    }

    bool isOpen(char c) {
      return matched_paren.find(c) != matched_paren.end();
    }
};

int main() {
  cout << Solution().isValid("[[][]]") << endl;
  cout << Solution().isValid("([)]") << endl;
  cout << Solution().isValid("[()[[]()]]") << endl;
}
