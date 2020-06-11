package main

func maxProfit(prices []int) int {
	if len(prices) == 0{
		return 0;
	}
	profit := 0
	min := prices[0]
	for i := 0; i < len(prices); i++ {
		if prices[i] < min {
			min = prices[i]
		}
		if profit < prices[i] - min {
			profit = prices[i] - min
		}
	}
	return profit
}
