class Solution {
    public int singleNumber(int[] nums) {
        int ans = 0;
        for (int i = 0; i<32; i++) {
            int sum = 0;
            for (int val : nums) {
                sum += (val>>i & 1);
            }
            sum  = sum%3;
            ans = ans | (sum<<i);
        }
        return ans;
    }
}