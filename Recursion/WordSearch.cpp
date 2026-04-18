class Solution {
public:
    vector<int> dirs = {1, 0, -1, 0, 1};
    bool findWord(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.size()) {
            return true;
        }
        int m = board.size(), n = board[0].size();
        bool found = false;
        for (int d = 0; d<4; d++) {
            int nx = i+dirs[d];
            int ny = j+dirs[d+1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] != '#' && board[nx][ny] == word[idx]) {
                char ch = board[nx][ny];
                board[nx][ny] = '#';
                found = found || findWord(board, word, nx, ny, idx+1);
                board[nx][ny] = ch;
            }
            if (found) break;
        }
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i<board.size(); i++) {
            for(int j = 0; j<board[0].size(); j++) {
                if (word[0] == board[i][j]) {
                    if (word.size() == 1) return true;
                    char ch = board[i][j];
                    board[i][j] = '#';
                    if (findWord(board, word, i, j, 1)) return true;
                    board[i][j] = ch;
                }
            }
        }
        return false;
    }
};