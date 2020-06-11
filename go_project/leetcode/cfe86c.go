package main

import "fmt"

func gcd(a int64, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	var tot = 0
	_, _ = fmt.Scanln(&tot)
	for i := 0; i < tot; i++ {
		var a int64= 0
		var b int64= 0
		var q int64= 0
		_, err := fmt.Scanln(&a, &b, &q)
		if err != nil {
			break
		}
		common := gcd(a, b)
		times := (a / common) * b
		for queries := int64(0); queries < q; queries ++ {
			var l int64 = 0
			var r int64 = 0
			_, err = fmt.Scanln(&l, &r)
			if err != nil {
				break
			}
			left := (l - 1) / times
			right := r / times
			leftMax := times * left
			rightMax := times * right
			var res int64 = 0
			if a > b {
				res = a - 1
			} else {
				res = b - 1
			}
			leftMax += res
			rightMax += res
			ans := (right - left) * (res + 1)
			if leftMax >= l {
				ans += leftMax - l + 1
			}
			if rightMax > r {
				ans -= rightMax - r
			}
			fmt.Print(r - l + 1 - ans, " ")
		}
		fmt.Println("")
	}
}
