#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// Runtime: 20 ms, faster than 75.33% of C++ online submissions for Valid Sudoku.
// Memory Usage: 18.1 MB, less than 69.37% of C++ online submissions for Valid Sudoku.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      int used[9][9] = {0};
      int used2[9][9] = {0};
      int used3[9][9] = {0};

      for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
          if (board[y][x] == '.') {
            continue;
          }

          int value = board[y][x] - '1';
          int k = x / 3 + y / 3 * 3;

          if (used[y][value] || used2[x][value] || used3[k][value]) {
            return false;
          }
          used[y][value] = 1;
          used2[x][value] = 1;
          used3[k][value] = 1;
        }
      }

      return true;
    }
};

int main() {
  auto s = Solution();
  vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
  cout << s.isValidSudoku(board) << endl;
}
