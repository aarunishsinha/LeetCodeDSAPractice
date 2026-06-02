class Solution {
    int solve(int mask, int currentSum, int maxVal, int target, int[] memo) {
        if (memo[mask] != -1) {
            return memo[mask];
        }
        for (int i = 1; i<=maxVal; i++) {
            if ((mask & 1<<i) == 0) {
                if (currentSum + i >= target) {
                    return memo[mask] = 1;
                }
                int newMask = mask | 1<<i;
                if (solve(newMask, currentSum+i, maxVal, target, memo) == 0) {
                    return memo[mask] = 1;
                }
            }
        }
        return memo[mask] = 0;
    }
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        int totalSum = maxChoosableInteger*(maxChoosableInteger + 1) / 2;
        if (totalSum < desiredTotal) {
            return false;
        }
        int[] memo = new int[1 << maxChoosableInteger + 1];
        Arrays.fill(memo, -1);
        return solve(0, 0, maxChoosableInteger, desiredTotal, memo) == 1;
    }
}