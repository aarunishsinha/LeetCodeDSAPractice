// DIJKSTRA APPROACH 
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        List<int[]>[] adj = new ArrayList[n];
        for (int i = 0; i<n; i++){
            adj[i] = new ArrayList<>();
        }
        for (int[] flight : flights) {
            adj[flight[0]].add(new int[]{flight[1], flight[2]});
        }
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> Integer.compare(a[1], b[1]));
        pq.offer(new int[]{src, 0, 0});
        int[][] dist = new int[n][k+2];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        Arrays.fill(dist[src], 0);
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int currNode = curr[0];
            int currDist = curr[1];
            int currHops = curr[2];
            if (currNode == dst) return currDist;
            if (currHops > k) continue;
            for (int[] nei : adj[currNode]) {
                if (nei[1]+currDist < dist[nei[0]][currHops+1]) {
                    dist[nei[0]][currHops+1] = currDist + nei[1];
                    pq.offer(new int[]{nei[0], dist[nei[0]][currHops+1], currHops+1});
                }
            }
        }
        int minCost = Integer.MAX_VALUE;
        for (int cost : dist[dst]) {
            minCost = Math.min(cost, minCost);
        }
        if (minCost == Integer.MAX_VALUE) return -1;
        else return minCost;
    }
}

// BFS APPROACH 
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        List<int[]>[] adj = new ArrayList[n];
        for (int i = 0; i<n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i<flights.length; i++) {
            int s = flights[i][0];
            int d = flights[i][1];
            int cost = flights[i][2];
            adj[s].add(new int[]{d, cost});
        }
        Queue<int[]> q = new ArrayDeque<>();
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        q.offer(new int[]{src, 0});
        int hops = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i<sz; i++) {
                int[] curr = q.poll();
                int currNode = curr[0];
                int currCost = curr[1];
                for (int[] nei : adj[currNode]) {
                    int newCost = currCost + nei[1];
                    if (dist[nei[0]] > newCost) {
                        dist[nei[0]] = newCost;
                        q.offer(new int[]{nei[0], newCost});
                    }
                }
            }
            hops++;
            if (hops > k) break;
        }
        if (dist[dst] == Integer.MAX_VALUE) return -1;
        else return dist[dst];
    }
}