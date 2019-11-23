package main

import (
	"fmt"
	"log"
	"os"
)

func main() {
	file, err := os.Open("input")
	if err != nil {
		log.Fatal(err)
	}
	file = os.Stdin

	var (
		q int
		n int
	)
	fmt.Fscanln(file, &q)

	for t := 0; t < q; t++ {
		fmt.Fscanln(file, &n)
		p := make([]int, n + 1)
		for i := 1; i <= n; i++ {
			fmt.Fscan(file, &p[i])
		}

		answer := make([]int, n + 1)
		visited := make([]bool, n + 1)
		for i := 1; i <= n; i++ {
			if visited[i] {
				continue
			}

			nxt := i
			visited[nxt] = true
			cycle := []int{nxt}
			for {
				nxt = p[nxt]
				if visited[nxt] {
					break
				}
				visited[nxt] = true
				cycle = append(cycle, nxt)
			}

			for _, vertex := range cycle {
				answer[vertex] = len(cycle)
			}
		}

		for i, item := range answer {
			if i != 0 {
				fmt.Print(item, " ")
			}
		}
		fmt.Println()
	}
}