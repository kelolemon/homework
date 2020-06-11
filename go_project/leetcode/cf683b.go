package main

import "fmt"

func main() {
	tot, k, n := 0, 0, 0
	_, _ = fmt.Scan(&tot)
	for i := 0; i < tot; i++ {
		_, _ = fmt.Scan(&n, &k)
		a := make([]int, n)
		for j := 0; j < n; j++ {
			_, _ = fmt.Scan(&a[j])
		}
		number := make(map[int]int)
		nub := 0
		for j := 0; j < n; j++ {
			if _, ok := number[a[j]]; ok {
				continue
			} else {
				number[a[j]] = 1
				nub = nub + 1
			}
		}
		if nub > k {
			fmt.Println("-1")
		} else {
			for j := 0; j < len(a) - k; j++ {
				if a[j] != a[j + k] {
					result := make([]int, len(a) + 1)
					copy(result, a[:k])
					result[k] = a[j]
					copy(result[k + 1:], a[k:])
					a = result
				}
			}
			fmt.Println(len(a))
			for j := 0; j < len(a); j++ {
				fmt.Printf("%d ", a[j])
			}
			fmt.Println("")
		}

 	}
}
