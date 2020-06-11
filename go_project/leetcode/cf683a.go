package main

import (
	"fmt"
	"math"
)

func main() {
	tot := 0
	n := 0
	_, _ = fmt.Scanln(&tot)
	for i := 0; i < tot; i++ {
		_, _ = fmt.Scanln(&n)
		ans := n / 2
		a := math.Pow(2, float64(n))
		for j := 1; j < ans; j++ {
			a = a + math.Pow(2, float64(j))
		}
		b := 0
		for j := ans; j < n; j++ {
			b = b + int(math.Pow(2, float64(j)))
		}
		ans = int(math.Abs(a - float64(b)))
		fmt.Println(ans)
	}
}
