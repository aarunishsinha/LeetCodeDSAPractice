class Solution {
private:
    vector<char> digits = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
public:
    bool solve(vector<vector<char>>& board, vector<vector<bool>>& square, vector<vector<bool>>& rows, vector<vector<bool>>& cols, int row, int col) {
        if (row == 9) {
            return true;
        }
        if (board[row][col] != '.') {
            if (col == 8) {
                return solve(board, square, rows, cols, row+1, 0);
            }
            else {
                return solve(board, square, rows, cols, row, col+1);
            }
        }
        else {
            int sqIdx = (row/3)*3 + (col/3);
            for (char& ch : digits) {
                if (square[sqIdx][ch-'1'] == false && rows[row][ch-'1'] == false && cols[col][ch-'1'] == false) {
                    square[sqIdx][ch-'1'] = true;
                    rows[row][ch-'1'] = true;
                    cols[col][ch-'1'] = true;
                    board[row][col] = ch;
                    if (col == 8) {
                        if(solve(board, square, rows, cols, row+1, 0)) return true;
                    }
                    else {
                        if(solve(board, square, rows, cols, row, col+1)) return true;
                    }
                    square[sqIdx][ch-'1'] = false;
                    rows[row][ch-'1'] = false;
                    cols[col][ch-'1'] = false;
                    board[row][col] = '.';
                }
            }
            return false;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> square(9, vector<bool>(9, false)), rows(9, vector<bool>(9, false)), cols(9, vector<bool>(9, false));
        for (int i = 0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                int sqIdx = (i/3)*3 + (j/3);
                if (board[i][j] != '.') {
                    square[sqIdx][board[i][j]-'1'] = true;
                    cols[j][board[i][j]-'1'] = true;
                    rows[i][board[i][j]-'1'] = true;
                }
            } 
        }
        solve(board, square, rows, cols, 0, 0);
    }
};