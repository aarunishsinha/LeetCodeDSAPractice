# Pattern: Intervals

This directory serves as an execution ledger for problems solved using the Intervals pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/description/) | 4m logic<br> 14m total | **Pattern:** Sort by Start <br>**Trigger:** "Merge Overlapping Intervals" | **Time:** `O(n*log(n))`<br>**Space:** `O(n)` | You need to merge intervals, hence sort by start. Merge intervals while iterating from left to right, if the start of the next interval is before the maximum end seen so far, merge it. | For a single element, the answer is that element |
| 2 | [23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | 13m logic<br> 18m total | **Pattern:** MinHeap <br>**Trigger:** "Merge k sorted lists" | **Time:** `O(k*n*log(k))`<br>**Space:** `O(k)` | Add all the list nodes in the minHeap and poll the smallest every time to build the merged list. Every time you poll a node, add the next node in that list back into the minHeap if it exists | If you have no lists, return an empty list |
| 3 | [295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) | 15m logic<br> 27m total | **Pattern:** MinHeap + MaxHeap <br>**Trigger:** "Median in Data Stream" | **Time:** addNum : `O(log n)`, findMedian : `O(1)`<br>**Space:** `O(n)` | Maintain two priority queues, one MaxHeap and one MinHeap. The MaxHeap shall store the smaller half of the numbers and the MinHeap shall store the larger half of the numbers. At any point in time the MaxHeap size is either same or one greater than the MinHeap size. When a new element arrives, add it to the MaxHeap and then move the largest element from the MaxHeap to the MinHeap. If the size of the MinHeap is larger than the MaxHeap you need to rebalance so move the smallest number from the MinHeap to the MaxHeap. The median is either the largest number in the MaxHeap (odd elements) or average of the top elements in the two heaps (even elements) | For 1 number, the number itself is the median |