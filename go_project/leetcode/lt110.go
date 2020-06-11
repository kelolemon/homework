package main

import "math"

var ans bool = true

func dfs(x *TreeNode) int {
	if x == nil {
		return 0
	}
	left := dfs(x.Left)
	right := dfs(x.Right)
	if math.Abs(float64(left-right)) > 1 {
		ans = false
		return 0
	}
	if left > right {
		return left + 1
	} else {
		return right + 1
	}
}

func isBalanced(root *TreeNode) bool {
	ans = true
	dfs(root)
	return ans
}
