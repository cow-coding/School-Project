package main

import ("fmt")

func ReverseInts(s []Int) {
  first := 0
  last := len(s) - 1

  for first < last {
    s[first], s[last] = s[last], s[first]
    first++
    last--
  }
}

func ReverseStrings(s []string) {
  first := 0
  last := len(s) - 1

  for first < last {
    s[first], s[last] = s[last], s[first]
    first++
    last--
  }
}

func Reverse(s []interface{}) {
  first := 0
  last := len(s) - 1

  for first < last {
    s[first], s[last] = s[last], s[first]
    first++
    last--
  }
}

// reflect package 사용도 가능함
func main() {
  // numbers := []int{1,2,3}
  // strings := []string{"인","하","대","학","교"}
  numbers := []interface{}{1,2,3}
  strings := []interface{}{"인","하","대","학","교"}
  Reverse(numbers)
  Reverse(strings)
}
