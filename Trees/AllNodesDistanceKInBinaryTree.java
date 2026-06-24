/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        // create adj list
        HashMap<Integer, List<Integer>> adj = new HashMap<>();
        Queue<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        adj.put(root.val, new ArrayList<Integer>());
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node.left != null) {
                adj.get(node.val).add(node.left.val);
                adj.put(node.left.val, new ArrayList<Integer>());
                adj.get(node.left.val).add(node.val);
                q.offer(node.left);
            }
            if (node.right != null) {
                adj.get(node.val).add(node.right.val);
                adj.put(node.right.val, new ArrayList<Integer>());
                adj.get(node.right.val).add(node.val);
                q.offer(node.right);
            }
        }
        // bfs and return k-th level from target
        boolean[] visited = new boolean[501];
        Arrays.fill(visited, false);
        Queue<Integer> bfsQ = new ArrayDeque<>();
        bfsQ.offer(target.val);
        visited[target.val] = true;
        List<Integer> result = new ArrayList<>();
        while (!bfsQ.isEmpty() && k > 0) {
            int sz = bfsQ.size();
            for (int i = 0; i<sz; i++) {
                int nod = bfsQ.poll();
                for (int j = 0; j<adj.get(nod).size(); j++) {
                    if (visited[adj.get(nod).get(j)] == false) {
                        bfsQ.offer(adj.get(nod).get(j));
                        visited[adj.get(nod).get(j)] = true;
                    }
                }
            }
            k--;
        }
        if (k == 0) {
            while (!bfsQ.isEmpty()) {
                result.add(bfsQ.poll());
            }
        }
        return result;
    }
}