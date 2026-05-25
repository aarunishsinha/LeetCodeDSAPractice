class Solution {
public:
    int solve(vector<int> &values, int l, int r, vector<vector<int>> &memo) {
        if (r-l+1 < 3) return 0;
        if (memo[l][r] != -1) return memo[l][r];
        int minScore = INT_MAX;
        for (int i = l+1; i<r; i++) {
            minScore = min(minScore, solve(values, l, i, memo) + values[l] * values[i] * values[r] + solve(values, i, r, memo));
        }
        return memo[l][r] = minScore;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(values, 0, n-1, memo);
    }
};