/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int height(TreeNode node) {
        if (node == null) return 0;
        int h1 = height(node.left);
        if (h1 == -1) return -1;
        int h2 = height(node.right);
        if (h2 == -1) return -1;
        if (Math.abs(h1-h2) > 1) {
            return -1;
        }
        return 1+ Math.max(h1, h2);
    }
    public boolean isBalanced(TreeNode root) {
        int h = height(root);
        return h != -1;
    }
}