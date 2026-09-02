class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int[] pre = new int[n+1];
        for (int i = 0; i<n; i++) {
            pre[i+1] = pre[i] + nums[i];
        }
        int maxSum = Integer.MIN_VALUE;
        int l = 0;
        for(int r = 1; r<n+1; r++) {
            maxSum = Math.max(maxSum, pre[r] - pre[l]);
            if (pre[r] < pre[l]) {
                l = r;
            }
        }
        return maxSum;
    }
}