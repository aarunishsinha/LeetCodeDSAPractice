class Solution {
    public int maxProfit(int[] prices) {
        int[][] dp = new int[prices.length+1][2];
        dp[0][0] = (int)-1e4;
        for (int i = 0; i<prices.length; i++) {
            dp[i+1][1] = Math.max(dp[i][0] + prices[i], dp[i][1]);
            if (i > 0) {
                dp[i+1][0] = Math.max(dp[i-1][1]-prices[i], dp[i][0]);
            }
            else {
                dp[i+1][0] = Math.max(-prices[i], dp[i][0]);
            }
        }
        return dp[prices.length][1];
    }
}