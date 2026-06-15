/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null) return new ListNode();
        ListNode head = new ListNode();
        ListNode tmp = head;
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a.val, b.val));
        for (ListNode list : lists) {
            if (list != null) minHeap.offer(list);
        }
        while( !minHeap.isEmpty()) {
            ListNode curr = minHeap.poll();
            tmp.next = curr;
            tmp = tmp.next;
            if (curr.next != null) {
                minHeap.offer(curr.next);
            }
        }
        return head.next;
    }
}