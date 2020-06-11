package main

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

var ans = make([][]int, 0)

func dfs(x *TreeNode, step int) {
	if x == nil {
		return
	}
	if len(ans) == step {
		ans = append(ans, make([]int, 0))
	}
	ans[step] = append(ans[step], x.Val)
	dfs(x.Left, step + 1)
	dfs(x.Right, step + 1)
}

func levelOrder(root *TreeNode) [][]int {
	ans = make([][]int, 0)
	dfs(root, 0)
	return ans
}