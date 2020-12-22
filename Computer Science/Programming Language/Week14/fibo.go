package main

import "fmt"

var dp [101]int

func fibo(n int) int {
	if n <= 1 {
		return 1
	}

	if dp[n] != 0 {
		return dp[n]
	}

	dp[n] = n * fibo(n-1)
	return dp[n]
}

func main() {
	fmt.Println(fibo(13))
}
