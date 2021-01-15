#include<vector>
#include<string>
#include<map>
using namespace std;
int main() {}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.size() == 0) return "";

      int i = 0;
      for (i = 0; i < strs[0].size(); i++) {
        bool ok = true;
        for (int j = 1; j < strs.size(); j++) {
          if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {
            ok = false;
            break;
          }
        }

        if (!ok) break;
      }

      return strs[0].substr(0, i);
    }
};
