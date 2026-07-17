class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if (n == 1) return 0;
        int currentIdx = 0;
        int maxReach = nums[0];
        int jumps = 1;
        while (maxReach < n-1) {
            int tmpIdx = currentIdx;
            int tmpReach = maxReach;
            for (int i = currentIdx+1; i<=maxReach; i++) {
                if (tmpReach < (i + nums[i])) {
                    tmpReach = i+nums[i];
                    tmpIdx = i;
                }
            }
            if (maxReach < tmpReach) {
                jumps++;
                maxReach = tmpReach;
                currentIdx= tmpIdx;
            }
        }
        return jumps++;
    }
}