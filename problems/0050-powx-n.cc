// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
// Memory Usage: 6 MB, less than 39.76% of C++ online submissions for Pow(x, n).

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n < 0) return 1.0 / myPow(x, -(n + 1)) / x;

        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        } else {
            return x * myPow(x, n - 1);
        }
    }
};
