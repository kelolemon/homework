package main

var step int = 0

func dfs(in []int, post []int) *TreeNode {
	if len(in) == 0 {
		return nil
	}
	n := len(post)
	x := new(TreeNode)
	x.Val =  post[n - step - 1]
	i := 0
	for i = 0; i < n; i ++ {
		if in[i] == post[n - step - 1] {
			break
		}
	}
	step = step + 1
	if i == len(in) - 1 {
		x.Right = dfs(make([]int, 0), post)
	} else {
		x.Right = dfs(in[i + 1:], post)
	}
	if i == 0 {
		x.Left = dfs(make([]int, 0), post)
	} else {
		x.Left = dfs(in[:i], post)
	}
	return x
}

func buildTree(inorder []int, postorder []int) *TreeNode {
	step = 0
	return dfs(inorder, postorder)
}