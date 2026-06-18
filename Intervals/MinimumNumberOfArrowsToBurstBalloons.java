class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        int numArrows = 1;
        int currEnd = points[0][1];
        for (int[] point : points) {
            if (point[0] > currEnd) {
                currEnd = point[1];
                numArrows++;
            }
        }
        return numArrows;
    }
}