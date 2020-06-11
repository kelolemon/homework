package main

var ans = make([][]int, 0)

func dfs(x *TreeNode, sum int, current int, subans []int) {
	if x == nil {
		return
	}
	if x.Right == nil && x.Left == nil {
		current += x.Val
		subans = append(subans, x.Val)
		sub := make([]int, len(subans))
		copy(sub, subans)
		if sum == current {
			ans = append(ans, sub)
			return
		}
		return
	}
	dfs(x.Right, sum, current + x.Val, append(subans, x.Val))
	dfs(x.Left, sum, current + x.Val, append(subans, x.Val))
}

func pathSum(root *TreeNode, sum int) [][]int {
	ans = make([][]int, 0)
	dfs(root, sum, 0, make([]int, 0))
	return ans
}