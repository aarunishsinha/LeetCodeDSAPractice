class Solution {
public:
    int solve(string &s, int i, int j, vector<vector<int>> &memo) {
        if (i > j) return 0;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (i == j) {
            return memo[i][j] = 1;
        }
        else if (s[i]==s[j]) {
            return memo[i][j] = 2+ solve(s, i+1, j-1, memo);
        }
        else {
            return memo[i][j] = max(solve(s, i+1, j, memo), solve(s, i, j-1, memo));
        }
    }
    int longestPalindromeSubseq(string s) {
        int maxLen = 0;
        int n = s.size();
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        return solve(s, 0, n-1, memo);
    }
};