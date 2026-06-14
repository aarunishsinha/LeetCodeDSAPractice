class Solution {
    class DSU {
        private int[] parent;
        private int[] size;

        public DSU(int n) {
            parent = new int[n+1];
            size = new int[n+1];
            Arrays.fill(size, 1);
            for (int i = 1; i<=n; i++) {
                parent[i] = i;
            }
        }

        public int getParent(int x) {
            if (parent[x] == x) {
                return x;
            }
            else return parent[x] = getParent(parent[x]);
        }

        public boolean union(int a, int b) {
            int pA = getParent(a);
            int pB = getParent(b);
            if (pA == pB) return false;
            if (size[pA] < size[pB]) {
                int temp = pB;
                pB = pA;
                pA = temp;
            }
            parent[pB] = pA;
            size[pA] += size[pB];
            return true;
        }
    }
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        DSU dsu = new DSU(n);
        for (int[] edge : edges) {
            if (dsu.union(edge[0], edge[1]) == false) {
                return edge;
            }
        }
        return new int[]{};
    }
}