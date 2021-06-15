#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
// Memory Usage: 8.3 MB, less than 7.54% of C++ online submissions for Decode Ways.

class Solution {
public:
    unordered_map<string, int> memo;
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        if (memo.find(s) != memo.end()) return memo[s];

        int result = 0;

        int n = s[0] - '0';
        if (s.size() == 1) {
            if (n == 0) {
                memo[s] = 0;
            } else {
                memo[s] = 1;
            }
            return memo[s];
        }

        if (n >= 1 && n <= 9) {
            result += numDecodings(s.substr(1));
        }

        int n2 = n * 10 + (s[1] - '0');

        if (s.size() == 2) {
            if (n2 >= 10 && n2 <= 26) {
                memo[s] = result + 1;
                return memo[s];
            } else {
                memo[s] = result;
                return result;
            }
        }

        if (n2 >= 10 && n2 <= 26) {
            result += numDecodings(s.substr(2));
        }

        memo[s] = result;
        return result;
    }
};

int main() {
    auto s = Solution();
    cout << s.numDecodings("12") << endl;
    cout << s.numDecodings("226") << endl;
    cout << s.numDecodings("001") << endl;

}
