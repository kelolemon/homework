package main

func maxProfit(prices []int) int {
	maxbuy := 0
	maxsell := 0
	maxbuytime := 0
	nowtime := 0
	n := len(prices)
	if n == 0 {
		return n
	}
	maxbuy = -prices[0]
	maxsell = 0
	for i := 1; i < n; i++ {
		buy := maxsell - prices[i]
		sell := maxbuy + prices[i]
		if maxbuy < buy && nowtime <= 1{
			maxbuy = buy
			nowtime = maxbuytime + 1
		}
		if maxsell < sell {
			maxsell = sell
			maxbuytime = nowtime
		}
	}
	return maxsell
}

