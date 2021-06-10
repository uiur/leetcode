// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sqrt(x).
// Memory Usage: 5.8 MB, less than 69.37% of C++ online submissions for Sqrt(x).

class Solution {
public:
    int mySqrt(int x) {
      if (x == 0) return 0;

      int i = 0;
      int j = x;
      while (i < j) {
        unsigned long long int m = (i + j) / 2 + 1;

        if (m * m == x)  return m;
        if (m * m > x) {
          j = m - 1;
        } else {
          i = m;
        }
      }

      return j;
    }
};
