package main


func dfs(left int, right int) []*TreeNode {
	if left > right {
		return append(make([]*TreeNode, 0), nil)
	}
	allTrees := make([]*TreeNode, 0)
	for i := left; i <= right; i++ {
		leftTree := dfs(left, i - 1)
		rightTree := dfs(i + 1, right)
		for leftRoot := range leftTree {
			for rightRoot := range rightTree {
				thisTree := new(TreeNode)
				thisTree.Val = i
				thisTree.Left = leftTree[leftRoot]
				thisTree.Right = rightTree[rightRoot]
				allTrees = append(allTrees, thisTree)
			}
		}
	}
	return allTrees
}

func generateTrees(n int) []*TreeNode {
	if n == 0 {
		return make([]*TreeNode, 0)
	}
	return dfs(1, n)
}