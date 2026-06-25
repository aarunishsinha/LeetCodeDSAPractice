class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> Integer.compare(b[2], a[2]));
        for (int[] point : points) {
            int distance = point[0]*point[0] + point[1]*point[1];
            if (maxHeap.size() == k) {
                if (maxHeap.peek()[2] > distance) {
                    maxHeap.poll();
                    maxHeap.offer(new int[]{point[0], point[1], distance});
                }
            }
            else {
                maxHeap.offer(new int[]{point[0], point[1], distance});
            }
        }
        int[][] res = new int[k][2];
        int idx = 0;
        while (!maxHeap.isEmpty()) {
            int[] elem = maxHeap.poll();
            res[idx][0] = elem[0];
            res[idx][1] = elem[1];
            idx++;
        }
        return res;
    }
}