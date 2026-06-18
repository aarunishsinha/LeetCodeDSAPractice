class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int count = 0; 
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));
        int currEnd = Integer.MIN_VALUE;
        for (int[] interval : intervals) {
            if (interval[0] >= currEnd) {
                currEnd = interval[1];
            }
            else {
                count++;
            }
        }
        return count;
    }
}