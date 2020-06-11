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

func reverse(s [][]int) [][]int {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func levelOrder(root *TreeNode) [][]int {
	ans = make([][]int, 0)
	dfs(root, 0)
	return reverse(ans)
}