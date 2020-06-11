package main

import "fmt"

func isInterleave(s1 string, s2 string, s3 string) bool {
	n := len(s1)
	m := len(s2)
	l := len(s3)
	dp := make([][][]bool, n + 1)
	for i := range dp {
		dp[i] = make([][]bool, m + 1)
		for j := range dp[i] {
			dp[i][j] = make([]bool, l + 1)
		}
	}
	dp[0][0][0] = true
	dp[1][0][1] = s1[0] == s3[0]
	dp[0][1][1] = s2[0] == s3[0]
	for i := 2; i <= l; i++ {
		for j := 0; j <= i && j <= n; j++ {
			k := i - j
			if k > m {
				continue
			}
			if j > 0 {
				dp[j][k][i] = dp[j][k][i] || dp[j-1][k][i-1] && s1[j-1] == s3[i-1]
			}
			if k > 0 {
				dp[j][k][i] = dp[j][k][i] || dp[j][k-1][i-1] && s2[k-1] == s3[i-1]
			}
		}
	}
	return dp[n][m][l]
}

func main() {
	a := "aabcc"
	b := "dbbca"
	c := "aadbbbaccc"
	fmt.Println(isInterleave(a, b, c))
}
