// Runtime: 12 ms, faster than 84.17% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 13.3 MB, less than 16.02% of C++ online submissions for Set Matrix Zeroes.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      bool row = false;
      bool column = false;
      int m = matrix.size();
      int n = matrix[0].size();
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (matrix[i][j] == 0) {
            if (i == 0) row = true;
            if (j == 0) column = true;
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
        }
      }

      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          if (matrix[i][0] == 0 || matrix[0][j] == 0) {
            matrix[i][j] = 0;
          }
        }
      }

      if (row) {
        for (int i = 0; i < n; i++) {
          matrix[0][i] = 0;
        }
      }

      if (column) {
        for (int i = 0; i < m; i++) {
          matrix[i][0] = 0;
        }
      }
    }
};
