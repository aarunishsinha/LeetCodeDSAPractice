/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    private void preorder(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append("null,");
        }
        else {
            sb.append(root.val).append(",");
            preorder(root.left, sb);
            preorder(root.right, sb);
        }
    }
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        preorder(root, sb);
        return sb.toString();
    }

    private TreeNode buildTree(Queue<String> q) {
        String val = q.poll();
        if (val.equals("null")) {
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(val));
        node.left = buildTree(q);
        node.right = buildTree(q);
        return node;
    }
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Queue<String> q = new ArrayDeque<>(Arrays.asList(data.split(",")));
        return buildTree(q);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));