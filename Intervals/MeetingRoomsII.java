/**
 * Definition of Interval:
 * public class Interval {
 *     public int start, end;
 *     public Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

class Solution {
    public int minMeetingRooms(List<Interval> intervals) {
        if (intervals.size() == 0) return 0;
        int n = intervals.size();
        int maxRooms = 0;
        int currRooms = 0;
        int[] start = new int[n];
        int[] end = new int[n];
        for (int i = 0; i<n; i++) {
            start[i] = intervals.get(i).start;
            end[i] = intervals.get(i).end;
        }
        Arrays.sort(start);
        Arrays.sort(end);
        int s = 0;
        int e = 0;
        while (s < n) {
            if (start[s] < end[e]) {
                currRooms++;
                s++;
            }
            else if (start[s] >= end[e]) {
                e++;
                currRooms--;
            }
            maxRooms = Math.max(maxRooms, currRooms);
        }
        return maxRooms;
    }
}