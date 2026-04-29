class Solution {
public:
    int solve(int n, vector<int>& numSquares) {
        if (n == 0) {
            return 0;
        }
        if (n < 0) {
            return INT_MAX;
        }
        if (numSquares[n] != -1) {
           return numSquares[n];
        }
        numSquares[n] = INT_MAX;
        for (int i = 1; i*i <=n; i++) {
            int val = solve(n-(i*i), numSquares);
            if (val != INT_MAX) {
                numSquares[n] = min(numSquares[n], val+1);
            }
        }
        return numSquares[n];
    }
    int numSquares(int n) {
        vector<int> numSquares(n+1, -1);
        numSquares[0] = 0;
        int res = solve(n, numSquares);
        return res;
    }
};