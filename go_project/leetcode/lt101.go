package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

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
	return dfs(x.Left, y.Right) && dfs(x.Right, y.Left)
}

func isSymmetric(root *TreeNode) bool {
	return dfs(root, root)
}