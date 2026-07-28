/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        Map<Node, Node> nodeMap = new HashMap<>();
        nodeMap.putIfAbsent(node, new Node(node.val));
        Queue<Node> bfs = new LinkedList<>();
        bfs.offer(node);
        while(!bfs.isEmpty()) {
            Node n = bfs.poll();
            for (Node m : n.neighbors) {
                if (!nodeMap.containsKey(m)) {
                    nodeMap.putIfAbsent(m, new Node(m.val));
                    bfs.offer(m);
                }
                nodeMap.get(n).neighbors.add(nodeMap.get(m));
            }
        }
        return nodeMap.get(node);
    }
}