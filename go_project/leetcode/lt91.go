package main

import (
	"fmt"
)

var ans = 0

func dfs(step int, n int, s string) {
	if step == n {
		ans++
		return
	}
	dfs(step + 1, n, s)
	if step + 1 < n && (s[step] - '0') * 10 + (s[step + 1] - '0') <= 26 {
		dfs(step + 2, n, s)
	}
}

func numDecodings(s string) int {
	n := len(s)
	ans = 0
	dfs(0, n, s)
	return ans
}

func main() {
	x := "12"
	fmt.Println(numDecodings(x))
}