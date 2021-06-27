// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
// Memory Usage: 8.8 MB, less than 10.28% of C++ online submissions for Plus One.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int i = digits.size() - 1;
      int carry = 1;
      while (i >= 0) {
        int sum = digits[i] + 1;
        digits[i] = sum % 10;
        if (sum / 10 == 0) break;
        i--;
      }

      if (i == -1) {
        digits.insert(digits.begin(), 1);
      }

      return digits;
    }
};
