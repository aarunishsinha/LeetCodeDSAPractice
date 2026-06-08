class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Integer>>[] adjList = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<>(); 
        }
        for (int i = 0; i< times.length; i++) {
            int[] time = times[i];
            List<Integer> dest = new ArrayList<>();
            dest.add(time[1]-1);
            dest.add(time[2]);
            adjList[time[0]-1].add(dest);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> Integer.compare(a[0], b[0]));
        pq.offer(new int[]{k-1, 0});
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[k-1] = 0;
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            Integer currNode = current[0];
            Integer currDist = current[1];
            if (currDist > dist[currNode]) {
                continue;
            }
            for (List<Integer> nei : adjList[currNode]) {
                Integer neiNode = nei.get(0);
                Integer edgeW = nei.get(1);
                if (currDist + edgeW < dist[neiNode]) {
                    dist[neiNode] = currDist + edgeW;
                    pq.offer(new int[]{neiNode, currDist + edgeW});
                }
            }
        }
        int maxDist = 0;
        for (int i = 0; i<n; i++) {
            if (dist[i] == Integer.MAX_VALUE) return -1;
            maxDist = Math.max(maxDist, dist[i]);
        }
        return maxDist;
    }
}