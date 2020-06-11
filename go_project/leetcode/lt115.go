package main

import "fmt"

func numDistinct(s string, t string) int {
	n := len(s)
	m := len(t)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, m)
	}
	if s[0] == t[0] {
		dp[0][0] = 1
	} else {
		dp[0][0] = 0
	}

	for i := 1; i < n; i++ {
		if s[i] == t[0] {
			dp[i][0] = dp[i - 1][0] + 1
		} else {
			dp[i][0] = dp[i - 1][0]
		}
	}

	for i := 1; i < m; i++ {
		for j := i ; j < n; j++ {
			if t[i] == s[j] {
				dp[j][i] = dp[j - 1][i - 1] + dp[j - 1][i]
			} else {
				dp[j][i] = dp[j - 1][i]
			}
		}
	}
	fmt.Println(dp)
	return dp[n - 1][m - 1]
}

func main() {
	s := "babgbag"
	t := "bag"
	_, _ = fmt.Scanf("%s", s)
	fmt.Println(numDistinct(s, t))
}
