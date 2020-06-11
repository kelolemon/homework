package main

import (
	"fmt"
)

func main() {
	var tot = 0
	_, _ = fmt.Scan(&tot)
	for i := 0; i < tot; i ++ {
		var a int64 = 0
		var b int64 = 0
		var x int64 = 0
		var y int64 = 0
		_, _ = fmt.Scan(&x, &y)
		_, _ = fmt.Scan(&a, &b)
		if x * y < 0 {
			if x < 0 {
				x = -x
			}
			if y < 0 {
				y = -y
			}
			ans1 := (x + y) * a
			fmt.Println(ans1)
		} else {
			if x < 0 {
				x = -x
			}
			if y < 0 {
				y = -y
			}
			var cnt int64 = 0
			if x < y {
				cnt = x
			} else {
				cnt = y
			}
			x -= cnt
			y -= cnt
			var fee int64 = 0
			if 2 * a > b {
				fee = b
			} else {
				fee = a * 2
			}
			ans := cnt * fee
			if x > 0 {
				ans += x * a
			} else {
				ans += y * a
			}
			fmt.Println(ans)
		}
	}
}