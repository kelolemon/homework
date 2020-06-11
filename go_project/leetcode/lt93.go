package main

import (
	"fmt"
	"strconv"
)

var ans = make([]string, 0)

func dfs(s string, subAns []int, step int, n int) {
	if len(subAns) == 4 {
		if step == n {
			addr := ""
			addr += strconv.Itoa(subAns[0]) + "." + strconv.Itoa(subAns[1]) + "." +
				strconv.Itoa(subAns[2]) + "." + strconv.Itoa(subAns[3])
			ans = append(ans, addr)
			return
		}
		return
	}
	if step == n {
		return
	}
	x1, _ := strconv.Atoi(s[step:step + 1])
	subAns = append(subAns, x1)
	dfs(s, subAns, step + 1, n)
	subAns = subAns[:len(subAns) - 1]
	if x1 > 0 && step + 1 < n {
		x2, _ := strconv.Atoi(s[step:step + 2])
		subAns = append(subAns, x2)
		dfs(s, subAns, step + 2, n)
		subAns = subAns[:len(subAns) - 1]
	}

	if x1 > 0 && step + 2 < n {
		x3, _ := strconv.Atoi(s[step:step + 3])
		if x3 <= 255 {
			subAns = append(subAns, x3)
			dfs(s, subAns, step+3, n)
			subAns = subAns[:len(subAns)-1]
		}
	}
}

func restoreIpAddresses(s string) []string {
	ans = make([]string, 0)
	n := len(s)
	subAns := make([]int, 0)
	dfs(s, subAns, 0, n)
	return ans
}

func main() {
	s := "25525511135"
	fmt.Println(restoreIpAddresses(s))
}