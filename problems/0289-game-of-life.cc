class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int ni = -1; ni <= 1; ni++) {
                    for (int nj = -1; nj <= 1; nj++) {
                        if (ni == 0 && nj == 0) continue;
                        if (!((0 <= (i + ni) && (i + ni) < m) && (0 <= (j + nj) && (j + nj) < n))) continue;
                        if (board[i + ni][j + nj] % 2 == 1) count++;
                    }
                }
                if (count == 2) {
                    board[i][j] += (board[i][j] << 1);
                }
                else if (count == 3) {
                    board[i][j] += 2;
                }
                
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
