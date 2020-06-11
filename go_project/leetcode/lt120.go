package main

import "math"

func minimumTotal(triangle [][]int) int {
	n := len(triangle)
	m := len(triangle[n - 1])
	f := make([]int, m)
	for i := 0; i < m; i++ {
		f[i] = triangle[n - 1][i]
	}
	for i := n - 2; i >= 0; i-- {
		for j := 0; j < n - 2; j++ {
			f[j] = int(math.Min(float64(f[j]), float64(f[j+1]))) + triangle[i][j]
		}
	}
	return f[0]
}

