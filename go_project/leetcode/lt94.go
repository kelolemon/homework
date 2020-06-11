package main

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

var ans = make([]int, 0)

func dfs(x *TreeNode) {
	if x == nil {
		return
	}
	dfs(x.Left)
	ans = append(ans, x.Val)
	dfs(x.Right)
}

func inorderTraversal(root *TreeNode) []int {
	ans = make([]int, 0)
	dfs(root)
	return ans
}
