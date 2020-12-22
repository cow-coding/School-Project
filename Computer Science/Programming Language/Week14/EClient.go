package main

import (
	"fmt"
	"log"
	"net"
	"time"
)

func main() {
	fmt.Println("에코 클라이언트 시작~")

	conn, err := net.Dial("tcp", ":10000")

	if err != nil {
		log.Fatal(err)
	}

	go func() {
		data := make([]byte, 4096)

		for {
			n, err := conn.Read(data)

			if err != nil {
				log.Fatal(err)
				return
			}

			log.Println("Server send : " + string(data[:n]))
			time.Sleep(time.Duration(3) * time.Second)
		}
	}()

	for {
		var s string
		fmt.Scanln(&s)
		conn.Write([]byte(s))
		time.Sleep(time.Duration(3) * time.Second)
	}
}
