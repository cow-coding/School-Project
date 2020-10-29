package main

import "fmt"

func sum_quiz(numbers ...int) int{
	r := 0
	for i := 0; i < len(numbers); i++ {
		r = r + numbers[i]
	}
	return r
}

func main() {
	nums := []int{1,5,3}
	fmt.Println(sum_quiz(nums...))
	fmt.Println(sum_quiz(1,3,5))
	nums[0] = 3
	nums[1] = 1
	nums[2] = 0
	fmt.Println(sum_quiz(nums...))
}
