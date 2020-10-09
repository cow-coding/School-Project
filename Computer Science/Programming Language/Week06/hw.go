package main

import (
	"fmt"
)

func main() {
	var subject map[string]string
	var sbj, prof string

	subject = make(map[string]string)
	subject["pl"] = "김인하"
	subject["oop"] = "이인하"
	subject["statistics"] = "최인하"

	for {
		fmt.Print("과목명: ")
		fmt.Scan(&sbj)

		fmt.Print("교수명: ")
		fmt.Scan(&prof)

		val, exists := subject[sbj]
		if exists {
			if val == prof {
				fmt.Println("수강신청 되었습니다.")
				break
			} else {
				fmt.Println("교수명을 확인하세요.")
			}
		} else {
			fmt.Println("해당 과목은 존재하지 않습니다.")
		}
	}
}
