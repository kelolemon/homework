package main

import "fmt"

func main() {
	var tot = 0
	_, _ = fmt.Scanln(&tot)
	for i := 0; i < tot; i++ {
		var s = ""
		_, _ = fmt.Scanln(&s)
		n := len(s)
		var f = true
		for i := 0; i < n - 2; i ++ {
			if s[i] != s[i + 2] {
				break
			}
			if i == len(s) - 3 {
				f = false
			}
		}
		if n <= 2 {
			f = false
			if n == 1 {
				s += s
			}
		}
		if !f {
			fmt.Println(s)
		} else {
			for i := 0; i < n; i++ {
				if i == n - 1 {
					break
				}
				if s[i] == s[i + 1] {
					var add = "1"
					if s[i] == '1' {
						add = "0"
					}
					s = s[:i + 1] + add + s[i + 1:]
					n = n + 1
				}
			}
			fmt.Println(s)
		}
	}
}
