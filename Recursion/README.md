# Pattern: Recursion

This directory serves as an execution ledger for problems solved using the Recursion pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [78. Subsets](https://leetcode.com/problems/subsets/description/) | 5m logic<br>10m total | **Pattern:** Backtracking<br>**Trigger:** "Return all possible subsets" | **Time:** `O(N*2^N)`<br>**Space:** `O(N*2^N)` | Used more memory initially due to not passing current subset by reference, push_back() performs a deep-copy adding `O(N)` time in every recursive call, hence time complexity becomes `O(N*2^N)` | -- |
| 2 | [77. Combinations](https://leetcode.com/problems/combinations/description/) | 4m logic<br>12m total | **Pattern:** Backtracking<br>**Trigger** "Return all combinations" | **Time:** `O(k * n! / k!)`<br>**Space:** `O(k * n! / k!)` | Pruning helps reduce the time and space needed | -- | 
| 3 | [46. Permutations](https://leetcode.com/problems/permutations/) | 9m logic<br>14m total | **Pattern:** Backtracking<br>**Trigger** "Return all permutations" | **Time:** `O(n * n!)`<br>**Space:** `O(n * n!)` | Maintain a visited array in order to not repeat elements | -- | 
| 4 | [90. Subsets II](https://leetcode.com/problems/subsets-ii/description/) | 3m logic<br>19m total | **Pattern:** Backtracking + Sorting<br>**Trigger** "Return all subsets without duplicates" | **Time:** `O(n * 2^n)`<br>**Space:** `O(n * 2^n)` | Initially used a set but that leeds for `O(n^2 * 2^n)` time complexity as set are RB trees and then comparing vector takes `O(n)`. Instead at each level in the recursive tree you can add only unique elements | [1, 4, 4] and [4, 1, 4] are the same | 
| 5 | [39. Combination Sum](https://leetcode.com/problems/combination-sum/description/) | 9m logic<br>19m total | **Pattern:** Backtracking<br>**Trigger** "Return all combinations with duplicates" | **Time:** `O(T/M * N^(T/M))`<br>**Space:** `O(T/M * N^(T/M))` | You can use a single elements as many times as possible. Largest possible combination is T/M where T is target and M is smallest element. In each recursive call you have N iterations and max depth is T/M hence the time and space complexity | -- | 
| 6 | [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | 15m logic<br>35m total | **Pattern:** Backtracking<br>**Trigger** "Return all combinations using each element only once" | **Time:** `O(T/M * N^(T/M))`<br>**Space:** `O(T/M * N^(T/M))` | Similar as Combination Sum but this time you can take each element only once, meaning start with increment in every recursive call | When duplicates on an element are present, to avoid creating duplicate combinations without using set you need to skip elements that are same as previous element in candidates but the previous element was not included in combination so far | 
