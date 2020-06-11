# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        present = head
        if head is None:
            return head
        set = 0
        step = 0
        while present is not None and present.next is not None:
            if present.val == present.next.val:
                set |= 1 << step
                set |= 1 << (step + 1)
            step = step + 1
            present = present.next
        present = head
        new_head = ListNode("HEAD")
        current = new_head
        step = 0
        while present is not None:
            if set & (1 << step) == 1 << step:
                present = present.next
                step = step + 1
                continue
            current.next = present
            current = current.next
            present = present.next
            step = step + 1
        current.next = None
        return new_head.next
