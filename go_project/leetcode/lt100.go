package main

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func dfs(x *TreeNode, y *TreeNode) bool {
	if x == nil && y ==nil {
		return true
	}

	if x == nil || y == nil {
		return false
	}

	if x.Val != y.Val {
		return false
	}
	return dfs(x.Left, y.Left) && dfs(x.Right, y.Right)
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	return dfs(p, q)
}
