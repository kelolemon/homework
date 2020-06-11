package main

import "math"

var ans = 0

func dfs(x *TreeNode, step int) {
	if x == nil {
		return
	}
	if step > ans {
		ans = step
	}
	dfs(x.Left, step + 1)
	dfs(x.Right, step + 1)
}

func maxDepth(root *TreeNode) int {
	ans = -1
	dfs(root, 0)
	return ans + 1
}