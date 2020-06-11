package main

import "fmt"

var tot = 0
var n = 0

func main() {
	_, _ = fmt.Scan(&tot)
	for i := 0; i < tot; i++ {
		_, _ = fmt.Scan(&n)
		exp := 2
		for j := 0; j < 32; j ++ {
			exp = exp * 2
			if n % (exp - 1) == 0 {
				fmt.Println(n / (exp - 1))
				break
			}
		}

	}
}
