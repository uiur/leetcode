#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// Runtime: 4 ms, faster than 48.49% of C++ online submissions for Divide Two Integers.
// Memory Usage: 6 MB, less than 21.40% of C++ online submissions for Divide Two Integers.

class Solution {
public:
    int divide(int dividend, int divisor) {
      int sign = 1;

      if (dividend < 0) {
        sign = -sign;
      }
      if (divisor < 0) {
        sign = -sign;
      }

      if (dividend == INT_MIN && sign < 0) {
        return INT_MAX;
      }

      long unsigned_dividend = abs(dividend);
      long unsigned_divisor = abs(divisor);

      // the number of loop is 2^31 =~ 10^9
      unsigned int i = 0;
      while (unsigned_dividend >= unsigned_divisor) {
        long count = 1;
        long tmp = unsigned_divisor;
        while (tmp << 1 <= unsigned_dividend) {
          count <<= 1;
          tmp <<= 1;
        }
        unsigned_dividend -= tmp;
        i += count;
      }

      return i * sign;
    }
};

int main() {
  auto s = Solution();
  cout << s.divide(7, -3) << endl;
}
