/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> solve(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        pair<int, int> left = solve(node->left);
        pair<int, int> right = solve(node->right);
        int rob = node->val + left.second + right.second;
        int skip = max(left.first, left.second) + max(right.first, right.second);
        return {rob, skip};
    }
    int rob(TreeNode* root) {
        // first = rob, second = skip
        pair<int, int> res = solve(root);
        return max(res.first, res.second);
    }
};