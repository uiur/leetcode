#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
// Runtime: 456 ms, faster than 17.51% of C++ online submissions for Word Search.
// Memory Usage: 7.3 MB, less than 68.72% of C++ online submissions for Word Search.

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j) {
      int m = board.size();
      int n = board[0].size();
      if (word.size() == 0) return true;
      if (!((0 <= i && i < m) && (0 <= j && j < n))) return false;
      if (board[i][j] != word[0]) return false;

      char c = board[i][j];
      board[i][j] = '#';
      string next_word = word.substr(1);
      bool result = dfs(board, next_word, i, j - 1) || dfs(board, next_word, i + 1, j) || dfs(board, next_word, i, j + 1) || dfs(board, next_word, i - 1, j);
      board[i][j] = c;
      return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j)) return true;
            }
        }
        return false;
    }
};

int main() {
  vector<vector<char>> v = {{'A','B','C'},{'B','A','C'}};
  auto s = Solution();
  cout << s.exist(v, "ABCCA") << endl;


}
