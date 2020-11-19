package main

import (
  "fmt"
)

func main() {
  fmt.Println("result:", func() int {return 1/0}()) // err

  fmt.Println("Finish!")
}
