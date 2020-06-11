# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        head_left = ListNode("HEAD")
        head_right = ListNode("HEAD")
        present_left = head_left
        present_right = head_right
        present = head
        while present is not None:
            if present.val < x:
                present_left.next = present
                present_left = present_left.next
            else:
                present_right.next = present
                present_right = present_right.next
            present = present.next
        present_right.next = None
        present_left.next = head_right.next
        return head_left.next
