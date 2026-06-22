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
    public boolean canAttendMeetings(List<Interval> intervals) {
        intervals.sort((a,b) -> Integer.compare(a.end, b.end));
        int end = -1;
        for (Interval inter : intervals) {
            if (inter.start < end) {
                return false;
            }
            else {
                end = inter.end;
            }
        }
        return true;
    }
}
