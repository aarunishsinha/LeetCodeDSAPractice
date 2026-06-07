# Pattern: Trie

This directory serves as an execution ledger for problems solved using the Trie pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) | 5m logic<br> 20m total | **Pattern:** Trie <br>**Trigger:**  | **Time:** `O(L)`<br>**Space:** `O(L)` |  |  |
| 2 | [211. Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/description/) | 3m logic<br> 26m total | **Pattern:** Trie + BFS <br>**Trigger:**  | **Time:** insert :`O(L)`, search : `O(26^L)` <br>**Space:** insert :`O(L)`, search :`O(L)` | Insert is straightforward. In search, each time you get a '.' you need to check all 26 branches | At the last index, if the character is '.' check if there is at least one branch with node->isEnd == true else check if the branch for the corresponding character has isEnd == true |
| 3 | [421. Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) | 18m logic<br> 47m total | **Pattern:** Bit Trie <br>**Trigger:**  | **Time:** insert :`O(32*N)`, maxXor : `O(N)` <br>**Space:** insert :`O(32*N)` | This trie forms a binary tree of fixed depth 32 since we have 32-bit integer. 31st bit down to 0th bit. For any number, to find the maximum Xor in the trie, traverse to the branch with the opposite bit wherever possible and calculate the xor at each level and accumulate | For a single element the xor is 0 |