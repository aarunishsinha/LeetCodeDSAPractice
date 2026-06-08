# Pattern: Graphs

This directory serves as an execution ledger for problems solved using the Graph pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [207. Course Schedule)](https://leetcode.com/problems/course-schedule/description/) | 5m logic<br> 20m total | **Pattern:** Topological Sorting <br>**Trigger:** "Dependency graph", "prerequisites" | **Time:** `O(V + E)`<br>**Space:** `O(V + E)` | For each node, compute the in-degrees. Start BFS from 0 in-degree nodes and as you visit nodes, reduce the in-degree of their neighbours. Add nodes to the queue only when their in-degree hits 0. At the end, if all nodes are visited then you can complete all courses else not | For a single course, you can always complete the course |