package main

import "fmt"

type ListNode struct {
	Val int
	Next *ListNode
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	newHead := new(ListNode)
	newHead.Next = head
	tot := n - m + 1
	present := newHead
	stack := make([]*ListNode, 0)
	for i :=1; i < m; i++ {
		present = present.Next
	}
	startPoint := present
	present = present.Next
	for i :=0; i < tot; i++ {
		stack = append(stack, present)
		present = present.Next
	}
	for len(stack) > 0 {
		startPoint.Next = stack[len(stack) - 1]
		stack = stack[:len(stack) - 1]
		startPoint = startPoint.Next
	}
	startPoint.Next = present
	return newHead.Next
}

func main() {
	head := new(ListNode)
	head.Val = 1
	next := new(ListNode)
	next.Val = 2
	head.Next = next
	end := new(ListNode)
	end.Val = 3
	next.Next = end
	test := reverseBetween(head, 1, 3)
	for test != nil {
		fmt.Println(test.Val)
		test = test.Next
	}

}
