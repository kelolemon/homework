# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

import heapq


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class MyPriorityQueue:
    def __init__(self):
        self._index = 0
        self.queue = []

    def push(self, priority, val):
        heapq.heappush(self.queue, (priority, self._index, val))
        self._index += 1

    def pop(self):
        return heapq.heappop(self.queue)[-1]

    def is_empty(self):
        return len(self.queue) == 0


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        ans = ListNode(0)
        last = ans
        priority_queue = MyPriorityQueue()
        for i in range(0, len(lists)):
            if lists[i] is not None:
                priority_queue.push(lists[i].val, (i, lists[i].val))
                lists[i] = lists[i].next
        while True:
            present = ListNode(0)
            top = priority_queue.pop()
            present.val = top[1]
            if lists[top[0]] is not None:
                priority_queue.push(lists[top[0]].val, (top[0], lists[top[0]].val))
                lists[top[0]] = lists[top[0]].next
            last.next = present
            last = present
            flag = 0
            for i in range(0, len(lists)):
                if lists[i] is not None:
                    flag = 1
                    break
            if flag == 0 and priority_queue.is_empty():
                break
        return ans.next

