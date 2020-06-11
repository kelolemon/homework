package main

import "fmt"

func numDecodings(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	}
	dp := make([]int, n)
	if s[0] == '0' {
		dp[0] = 0
	} else {
		dp[0] = 1
	}
	for i := 1; i < n; i++ {
		flag1 := s[i] != '0'
		flag2 := (s[i - 1] - '0') * 10 + (s[i] - '0') <= 26
		flag3 := dp[i - 1] > 0
		if flag1 && flag2 {
			dp[i] = dp[i - 1] + 1
		} else {
			if flag1 || flag2 {
				dp[i] = dp[i-1]
			}
		}
		if !flag3 {
			dp[i] = 0
		}
		if !flag1 && !flag2 {
			dp[i] = 0
		}
	}
	return dp[n - 1]
}

func main() {
	s := "226"
	fmt.Println(numDecodings(s))
}