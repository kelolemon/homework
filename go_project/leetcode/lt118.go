package main

import "fmt"

func generate(numRows int) [][]int {
	f := make([][]int, numRows)
	for i := 0; i < numRows; i++ {
		f[i] = make([]int, 0)
		f[i] = append(f[i], 1)
	}
	if numRows == 1 {
		return f
	}
	for i := 1; i < numRows; i++ {
		for j := 0; j < i -1; j ++ {
			f[i] = append(f[i], f[i - 1][j] + f[i - 1][j + 1])
		}
		f[i] = append(f[i], 1)
	}
	return f
}

func main() {
	n := 5
	fmt.Println(generate(n))
}