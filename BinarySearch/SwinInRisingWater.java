class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int l = 0;
        int r = n*n;
        while (l < r) {
            int mid = l + (r-l)/2;
            // is mid a valid solution?
            boolean[][] visited = new boolean[n][n];
            Queue<int[]> bfsQ = new ArrayDeque<>();
            if (grid[0][0] > mid) {
                l = mid + 1;
                continue;
            }
            bfsQ.offer(new int[]{0, 0});
            visited[0][0] = true;
            int[] dir = new int[]{-1, 0, 1, 0, -1};
            boolean found = false;
            while (!bfsQ.isEmpty()) {
                int[] elem = bfsQ.poll();
                if (elem[0] == n-1 && elem[1] == n-1) {
                    found = true;
                    break;
                }
                for (int d = 0; d<4; d++) {
                    int nx = elem[0] + dir[d];
                    int ny = elem[1] + dir[d+1];
                    if (nx >= 0 && ny >= 0 && nx < n && ny< n && grid[nx][ny] <= mid && !visited[nx][ny]) {
                        bfsQ.offer(new int[]{nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
            if (found) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
}