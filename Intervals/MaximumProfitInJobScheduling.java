class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for (int i = 0; i<n; i++) {
            jobs[i] = new int[]{startTime[i], endTime[i], profit[i]};
        }
        Arrays.sort(jobs, (a, b)-> Integer.compare(a[1], b[1]));

        TreeMap<Integer, Integer> dp = new TreeMap<>();
        dp.put(0,0);
        for (int i = 0; i<n; i++) {
            int start = jobs[i][0];
            int end = jobs[i][1];
            int prof = jobs[i][2];
            int maxProfitBefore = dp.floorEntry(start).getValue();
            int currentProfit = maxProfitBefore + prof;
            if (currentProfit > dp.lastEntry().getValue()) {
                dp.put(end, currentProfit);
            }
        }
        return dp.lastEntry().getValue();
    }
}

