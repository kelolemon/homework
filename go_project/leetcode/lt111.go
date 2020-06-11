package main

import "math"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(x *TreeNode) int {
	if x == nil {
		return 0
	}
	left := dfs(x.Left)
	right := dfs(x.Right)
	if left == 0 {
		left = right
	}
	if right == 0 {
		right = left
	}
	return int(math.Min(float64(left), float64(right))) + 1
}

func minDepth(root *TreeNode) int {
	return dfs(root)
}
