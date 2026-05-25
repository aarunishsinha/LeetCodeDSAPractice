// TOP-DOWN APPROACH

class Solution {
public:
    int solve(vector<int>& nums, int l, int r, vector<vector<int>> &memo) {
        if (l > r) return 0;
        if (l == r) {
            return nums[l-1]*nums[l]*nums[l+1];
        }
        if (memo[l-1][r-1] != -1) return memo[l-1][r-1];
        int maxCoins = 0;
        for(int i = l; i<=r; i++) {
            maxCoins = max(maxCoins, solve(nums, l, i-1, memo) + nums[l-1]*nums[i]*nums[r+1] + solve(nums, i+1, r, memo));
        }
        return memo[l-1][r-1] = maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        // solve(l, r) = max({solve(l, i-1) + nums[l-1]*nums[i]*nums[r+1] + solve(i+1, r) | for all i in [l, r]})
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return solve(nums, 1, n, memo);
    }
};

// BOTTOM-UP APPROACH

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for (int size = 1; size <= n; size++) {
            for (int start = 1; start <= (n-size+1); start++) {
                int maxCoins = 0;
                int end = start+size-1;
                for (int i = start; i<=end; i++) {
                    maxCoins = max(maxCoins, dp[start][i-1] + nums[start-1]*nums[i]*nums[end+1] + dp[i+1][end]);
                }
                dp[start][end] = maxCoins;
            }
        }
        return dp[1][n];
    }
};