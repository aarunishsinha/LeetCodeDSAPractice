class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer>[] adjList = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            adjList[i] = new ArrayList<>();
        }
        int[] inDeg = new int[numCourses];
        for (int[] edge : prerequisites) {
            inDeg[edge[0]]++;
            adjList[edge[1]].add(edge[0]);
        }
        Queue<Integer> q = new ArrayDeque<Integer>();
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i<numCourses; i++) {
            if (inDeg[i] == 0) {
                q.offer(i);
                res.add(i);
            }
        }
        while (!q.isEmpty()) {
            Integer course = q.poll();
            for (Integer nei : adjList[course]) {
                inDeg[nei]--;
                if (inDeg[nei] == 0) {
                    q.offer(nei);
                    res.add(nei);
                }
            }
        }
        if (res.size() == numCourses) {
            int[] fin = new int[numCourses];
            for (int i = 0; i<numCourses; i++) {
                fin[i] = res.get(i);
            }
            return fin;
        }
        return new int[0];
    }
}