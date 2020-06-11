package main

import "math/big"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

var first *int = nil
var second *int = nil
var pre *int = nil

func dfs(x *TreeNode) {
	if x == nil {
		return
	}
	dfs(x.Left)
	if pre !=nil && *pre > x.Val {
		if first == nil {
			first = pre
		}
		second = &x.Val
	}
	pre = &x.Val
	dfs(x.Right)
}

func recoverTree(root *TreeNode)  {
	first = nil
	second = nil
	pre = nil
	dfs(root)
	*first, *second = *second, *first
}

func main() {

}