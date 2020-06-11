package main

import (
	"fmt"
	"sort"
)

var ans = make([][]int, 0)

func dfs(subAns []int, step int, n int, nums []int) {
	if step == n {
		fmt.Println(subAns)
		tmp := make([]int, len(subAns))
		copy(tmp, subAns)
		ans = append(ans, tmp)
		return
	}
	subAns = append(subAns, nums[step])
	dfs(subAns, step + 1, n, nums)
	subAns = subAns[:len(subAns) - 1]
	for step < n - 1 && nums[step] == nums[step + 1] {
		step = step + 1
	}
	dfs(subAns, step + 1, n, nums)
}

func subsetsWithDup(nums []int) [][]int {
	n := len(nums)
	sort.Ints(nums)
	ans = make([][]int, 0)
	dfs(make([]int, 0), 0, n, nums)
	return ans
}

func main() {
	a := []int {1, 2, 2}
	fmt.Println(subsetsWithDup(a))
}
