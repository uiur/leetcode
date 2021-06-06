// Runtime: 4 ms, faster than 58.65% of C++ online submissions for Rotate Image.
// Memory Usage: 7.2 MB, less than 27.86% of C++ online submissions for Rotate Image.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
         for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                matrix[y][x] += 1000;
            }

         }
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                matrix[x][n - y - 1] += 2001 * (matrix[y][x] % 2001);
            }
        }
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                matrix[y][x] = matrix[y][x] / 2001 - 1000;
            }
        }

    }
};
