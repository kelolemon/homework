# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        present = head
        while present is not None and present.next is not None:
            while present.val == present.next.val:
                present.next = present.next.next
                if present.next is None:
                    return head
            present = present.next
        return head
