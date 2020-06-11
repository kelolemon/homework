package main

var step int = 0

func dfs(pre []int, in []int) *TreeNode{
	if len(in) == 0 {
		return nil
	}
	x := new(TreeNode)
	x.Val = pre[step]
	i := 0
	for i = 0; i < len(in); i ++ {
		if in[i] == pre[step] {
			break
		}
	}
	step = step + 1
	if i == 0 {
		x.Left = dfs(pre, make([]int, 0))
	} else {
		x.Left = dfs(pre, in[:i])
	}
	if i == len(in) - 1 {
		x.Right = dfs(pre, make([]int, 0))
	} else {
		x.Right = dfs(pre, in[i + 1:])
	}
	return x
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	step = 0
	return dfs(preorder, inorder)
}
