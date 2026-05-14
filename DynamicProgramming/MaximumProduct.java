class Solution {
    public int maxProduct(int[] nums) {
        int minProd = nums[0];
        int maxProd = nums[0];
        int res = nums[0];
        for (int i = 1; i<nums.length; i++) {
            int temp = maxProd;
            maxProd = Math.max(Math.max(minProd*nums[i], maxProd*nums[i]), nums[i]);
            minProd = Math.min(Math.min(minProd*nums[i], temp*nums[i]), nums[i]);
            res = Math.max(Math.max(minProd, maxProd), res);
        }
        return res;
    }
}