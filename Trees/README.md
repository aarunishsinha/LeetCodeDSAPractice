# Pattern: Trees

This directory serves as an execution ledger for problems solved using the Tree pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [863. All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) | 3m logic<br> 20m total | **Pattern:** Tree Traveral + BFS <br>**Trigger:** "nodes at distance k from target" | **Time:** `O(V+E) = O(V)` (in binary tree E = V-1) <br>**Space:** `O(L)` | Create an adjacency list from the tree and perform bfs level by level | For only root, if k = 0 then that is the node |
| 2 | [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | 5m logic<br> 20m total | **Pattern:** Post Order Traversal <br>**Trigger:** "lowest common ancestor" | **Time:** `O(n)` <br>**Space:** `O(h)` (height of tree) | In post order traversal bubble up when you find either `p` or `q`. If at any point, if both left and right children are not null then p and q are in different sub-tree and current node is the LCA otherwise either `p` or `q` is the LCA | For no tree the result is null |
| 3 | [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) | 15m logic<br> 35m total | **Pattern:** Pre-Order Traversal <br>**Trigger:** "Serialise and Deserialize" | **Time:** `O(n)` <br>**Space:** `O(n)` | As you know pre-order traversal is often used to recreate trees or copy trees, you can use it to simply serialise the tree. To deserialize, again perform preorder traversal after performing a split on the String. Store it in a Queue and poll everytime you add a node as in Java you cannot pass integer by reference and queue will handle this inherently | For root as null the String is `null,` and deserialise also gives null |