// Last updated: 02/08/2026, 09:02:40
class Solution {
private:
    // Beginner-friendly helper function placed outside of solve()
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') return;

        board[i][j] = '#'; // Mark as visited/safe

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            dfs(board, i + dx[k], j + dy[k], n, m);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        // 1. DFS from boundary 'O's
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0, n, m);
            if (board[i][m-1] == 'O') dfs(board, i, m-1, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j, n, m);
            if (board[n-1][j] == 'O') dfs(board, n-1, j, n, m);
        }

        // 2. Finalize: # -> O, O -> X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
