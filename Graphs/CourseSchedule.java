class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        for (int i = 0; i < numCourses; i++) {
            adjList.putIfAbsent(i, new ArrayList<>());
        }
        int[] inDeg = new int[numCourses];
        for (int[] edge : prerequisites) {
            adjList.get(edge[1]).add(edge[0]);
            inDeg[edge[0]]++;
        }
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i<numCourses; i++) {
            if (inDeg[i] == 0) {
                q.offer(i);
            }
        }
        while(!q.isEmpty()) {
            int course = q.poll();
            List<Integer> neighbours = adjList.get(course);
            for (int i = 0; i<neighbours.size(); i++) {
                int c1 = neighbours.get(i);
                inDeg[c1]--;
                if (inDeg[c1]==0) {
                    q.offer(c1);
                }
            }
        }
        for (int i = 0; i<numCourses; i++) {
            if (inDeg[i] != 0) return false;
        }
        return true;
    }
}