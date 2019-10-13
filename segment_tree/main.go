package main

import "fmt"

var (
	n = 8
	a = []int{7, 2, 3, 4, 5, 6, 7, 0}

	tree = make([]int, 2 * n)
)

func build() {
	for i := 0; i < n; i++ {
		tree[i + n] = a[i]
	}
	for i := n - 1; i >= 1; i-- {
		tree[i] = tree[i * 2] + tree[i * 2 + 1]
	}
}

func sum(v, tl, tr, l, r int) int {
	if tl > tr {
		return 0
	}
	if tr < l || tl > r {
		return 0
	}
	if tl >= l && tr <= r {
		return tree[v]
	}
	middle := (tl + tr) / 2
	return sum(v * 2, tl, middle, l, r) + sum(v * 2 + 1, middle + 1, tr, l, r)
}

func update(v, value int) {
	tree[v + n] = value
	updHelper((v + n) / 2, value)
}

func updHelper(v, value int) {
	if v <= 0 {
		return
	}
	tree[v] = tree[v * 2] + tree[v * 2 + 1]
	updHelper(v / 2, value)
}

func main() {
	build()
	fmt.Println(tree)

	fmt.Println(sum(1, 0, n - 1, 0, 3)) // 16
	fmt.Println(sum(1, 0, n - 1, 0, 5)) // 27
	fmt.Println(sum(1, 0, n - 1, 0, 2)) // 12
	fmt.Println(sum(1, 0, n - 1, 0, 4)) // 21
	fmt.Println()

	update(2, 6)

	fmt.Println(sum(1, 0, n - 1, 0, 3)) // 19
	fmt.Println(sum(1, 0, n - 1, 0, 5)) // 30
	fmt.Println(sum(1, 0, n - 1, 0, 2)) // 15
	fmt.Println(sum(1, 0, n - 1, 0, 4)) // 24
	fmt.Println()

	fmt.Println(sum(1, 0, n - 1, 2, 5)) // 21
}