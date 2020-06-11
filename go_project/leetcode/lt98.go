package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var ans = make([]int, 0)

func check(x *TreeNode) {
	if x == nil {
		return
	}
	check(x.Left)
	ans = append(ans, x.Val)
	check(x.Right)
}

func isValidBST(root *TreeNode) bool {
	ans = make([]int, 0)
	check(root)
	n := len(ans)
	for i := 0; i < n - 1; i++ {
		if ans[i] >= ans[i + 1] {
			return false
		}
	}
	return true
}