package main

func dfs(x *TreeNode, newNode *TreeNode) {
	if x == nil {
		return
	}
	tmp := new(TreeNode)
	tmp.Val = x.Val
	newNode.Right = tmp
	dfs(x.Left, newNode.Right)
	dfs(x.Right, newNode.Right)
}

func flatten(root *TreeNode)  {
	newRoot := new(TreeNode)
	dfs(root, newRoot)
	root = newRoot
}
