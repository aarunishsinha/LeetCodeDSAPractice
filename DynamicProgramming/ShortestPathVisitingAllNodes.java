class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        if (n == 1 && graph[0].length == 0) return 0;
        boolean[][] memo = new boolean[n][1<<n+1];
        Queue<int[]> q = new ArrayDeque<>();

        for (int i = 0; i<n; i++) {
            int initialMask = 1 << i;
            q.offer(new int[]{i, initialMask, 0});
            memo[i][initialMask] = true;
        }

        while (!q.isEmpty()) {
            int[] item = q.poll();
            int node = item[0];
            int mask = item[1];
            int dist = item[2];
            for (int neighbour : graph[node]) {
                int nextMask = mask | 1 << neighbour;
                if (nextMask == (1 << n)-1) {
                    return dist+1;
                }
                if (!memo[neighbour][nextMask]) {
                    memo[neighbour][nextMask] = true;
                    q.offer(new int[]{neighbour, nextMask, dist+1});
                }
            }
        }
        return 0;
    }
}