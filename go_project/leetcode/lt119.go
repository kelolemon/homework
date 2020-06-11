package main

import "fmt"

func getFac(n int64) int64 {
	if n == 0 {
		return 1
	}
	ans := int64(1)
	for i := int64(2); i <= n; i++ {
		ans *= i
	}
	return ans
}

func getCom(n int, m int) int {
	x := getFac(int64(m))
	fmt.Println(x)
	y := getFac(int64(n))
	z := getFac(int64(m - n))
	return int(x / (y * z))
}

func getRow(rowIndex int) []int {
	f := make([]int, 0)
	for i := 0; i <= rowIndex; i ++ {
		f = append(f, getCom(i, rowIndex))
	}
	return f
}

func main() {
	n := 21
	fmt.Println(getRow(n))
}