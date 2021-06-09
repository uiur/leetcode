// Runtime: 8 ms, faster than 11.23% of C++ online submissions for Unique Paths.
// Memory Usage: 6.1 MB, less than 44.56% of C++ online submissions for Unique Paths.

class Solution {
public:
    int memo[200][200];

    int combination(int m, int n) {
      if (n == 1) return m;
      if (m == n) return 1;
      int result = combination(m - 1, n - 1) + combination(m - 1, n);
      memo[m-1][n-1] = result;
      return result;
    }

    int uniquePaths(int m, int n) {
      for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
          memo[i][j] = -1;
        }
      }

      if (m == 1 || n == 1) return 1;
      return combination((m - 1) + (n - 1), m - 1);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
// Memory Usage: 6.5 MB, less than 25.72% of C++ online submissions for Unique Paths.
class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<int> dp(m, vector<int>(n, 1));
      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }

      return dp[m-1][n-1];
    }
};
