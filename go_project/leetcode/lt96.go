package main

import "fmt"

func numTrees(n int) int {
	ans := 1
	for i := 0; i < n; i++ {
		ans = ans * 2 * (2 * i + 1) / (i + 2)
	}
	return ans
}

func main() {
	fmt.Println(numTrees(5))
}