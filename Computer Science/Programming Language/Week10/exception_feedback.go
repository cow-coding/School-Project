package main

import (
  "fmt"
)

func main() {
  fmt.Println("result:", divide(1,0))

  fmt.Println("Finish!")
}

func divide(a, b int) int {
  defer func ()  {
    if err := recover(); err != nil {
      fmt.Println(err)
    }
  }()

  return a/b
}

// defer는 스택에 쌓고 pop되는 형식으로 진행된다.
// defer, panic, recover등을 활용해서 예외 처리를 함
/*
fmt.Println("1")
defer fmt.Println("2")
defer fmt.Println("3")
fmt.Println("4")

이 경우 1 4 3 2로 출력
*/
