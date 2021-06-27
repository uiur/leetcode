#include<vector>
#include<string>
#include<map>
#include<iostream>
using namespace std;

// Runtime: 8 ms, faster than 25.94% of C++ online submissions for Implement strStr().
// Memory Usage: 6.8 MB, less than 30.61% of C++ online submissions for Implement strStr().
class Solution {
public:
    int strStr(string haystack, string needle) {
      if (needle.size() == 0) { return 0; }

      int h = haystack.size();
      int n = needle.size();
      for (int i = 0; i < h - n + 1; i++) {
        int j = 0;
        for (; j < n; j++) {
          if (haystack[i + j] != needle[j]) {
            break;
          }
        }

        if (j == n) {
          return i;
        }
      }

      return -1;
    }
};

int main() {
  auto s = Solution();
  cout << s.strStr("aa", "aa") << endl;
  s.strStr("", "aaabbb");
}
