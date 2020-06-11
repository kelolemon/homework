package main

func dfs(nums []int) *TreeNode{
	n := len(nums)
	if n == 0 {
		return nil
	}
	x := new(TreeNode)
	i := n / 2
	x.Val = nums[i]
	x.Left = dfs(nums[:i])
	x.Right = dfs(nums[i + 1:])
	return x
}

func sortedArrayToBST(nums []int) *TreeNode {
	return dfs(nums)
}
