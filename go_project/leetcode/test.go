package main

import "fmt"

func main() {
	test := make([][]int, 0)
	a := make([]int, 3)
	b := make([]int, 4)
	test = append(test, a)
	test = append(test, b)
	fmt.Println(test)
}
