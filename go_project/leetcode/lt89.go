package main

import (
	"fmt"
	"math"
)

func grayCode(n int) []int {
	x := int(math.Pow(2, float64(n)) )
	ans := make([]int, x)
	for i := 0; i < x; i++ {
		ans[i] = i ^ (i >> 1)
	}
	return ans
}

func main() {
	fmt.Println(grayCode(2))
}