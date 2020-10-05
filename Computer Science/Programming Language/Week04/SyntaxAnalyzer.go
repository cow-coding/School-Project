// Q. 영상을 참고해서 구문분석기를 Java 또는 Go로 구현하시오.

package main

import "fmt"

var lookahead int = 0

func match(c int){
   if c == lookahead {
      fmt.Scanf("%c", &lookahead)
   } else{
      fmt.Printf("Syntax error : ")
      fmt.Printf("%c\n", lookahead)
   }
}

func S(){
   if lookahead == '(' {
      match('(')
      S()
      match(')')
      S()
   }
}

func K(){
   if lookahead != 0 {
      S()
      match('\n')
      K()
   }
}

func main(){
   fmt.Scanf("%c", &lookahead)
   K();
}
