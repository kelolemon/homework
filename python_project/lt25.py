# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class NewNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        self.pre = None


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if head is None:
            return head
        present = head
        new_head: NewNode
        new_head = NewNode(0)
        new_last = new_head
        while present is not None:
            new_present = NewNode(0)    
            new_present.val = present.val
            new_present.pre = new_last
            new_last.next = new_present
            new_last = new_present
            present = present.next
        first = new_head.next
        second = first
        while True:
            flag = 0
            for i in range(0, k - 1):
                second = second.next
                if second is None:
                    flag = 1
                    break
            if flag == 1:
                break;
            left = first
            right = second
            while left != right and left != right.next:
                left.val, right.val = right.val, left.val
                left = left.next
                right = right.pre
            first = second.next
            if first is None:
                break
            second = first
        return new_head.next
