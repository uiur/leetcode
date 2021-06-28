// Runtime: 4 ms, faster than 41.52% of C++ online submissions for Excel Sheet Column Number.
// Memory Usage: 6 MB, less than 56.19% of C++ online submissions for Excel Sheet Column Number.

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            result *= 26;
            result += columnTitle[i] - 'A' + 1;
        }
        return result;
    }
};
