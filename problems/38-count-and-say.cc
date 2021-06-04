// Runtime: 52 ms, faster than 7.31% of C++ online submissions for Count and Say.
// Memory Usage: 46.4 MB, less than 22.67% of C++ online submissions for Count and Say.

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);
        int i = prev.size() - 1;
        string result = "";
        while (i >= 0) {
            int count = 1;
            while (i - count >= 0) {
                if (prev[i - count] != prev[i]) break;
                count++;
            }

            result = (to_string(count)) + prev[i] + result;

            i -= count;
        }

        return result;
    }
};
