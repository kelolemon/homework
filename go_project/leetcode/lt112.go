package main


var ans bool = false

func dfs(x *TreeNode, sum int, current int, isleaf bool) {
	if x == nil {
		if sum == current && isleaf {
			ans = true
			return
		}
		return
	}
	if x.Right == nil && x.Left == nil {
		isleaf = true
	} else {
		isleaf = false
	}
	dfs(x.Right, sum, current + x.Val, isleaf)
	dfs(x.Left, sum, current + x.Val, isleaf)
}

func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	}
	ans = false
	dfs(root, sum, 0, false)
	return ans
}


