# Pattern: Linked List

This directory serves as an execution ledger for problems solved using the Linked List pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [146. LRU Cache](https://leetcode.com/problems/lru-cache/description/) | 7m logic<br>45m total | **Pattern:** HashMap + LinkedList<br>**Trigger:** "O(1) retreival", "key-value storage", "O(1) swapping elements while maining order" | **Time:** `O(1)`<br>**Space:** `O(1)` | Moving a middle element to the front(MRU) or removing an element from the end(LRU) is possbile if we have a doubly linked list with a head and tail dummy nodes | If cache is full, remove LRU and then add new node as MRU |