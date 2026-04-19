class Solution {
public:
    void formPlacement(int& n, vector<string>& board, int start, vector<vector<string>>& result, vector<bool>& backDiag, vector<bool>& fwdDiag, vector<bool>& up) {
        if (start == n) {
            result.push_back(board);
        }
        for (int j = 0; j<n; j++) {
            if (!backDiag[start-j+n] && !fwdDiag[start+j] && !up[j]) {
                backDiag[start-j+n] = true;
                fwdDiag[start+j] = true;
                up[j] = true;
                board[start][j] = 'Q';
                formPlacement(n, board, start+1, result, backDiag, fwdDiag, up);
                board[start][j] = '.';
                backDiag[start-j + n] = false;
                fwdDiag[start+j] = false;
                up[j] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> backDiag(2*n, false), fwdDiag(2*n, false), up(n, false);
        formPlacement(n, board, 0, result, backDiag, fwdDiag, up);
        return result;
    }
};