/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 22/03/2023 March 14:20:32 CST
 * algorithm:
 * description:
 * n
 * a1 a2 ...
 */

package main

import "fmt"

const maxn int = 1e5 + 5

var n, k int
var a [maxn]int

// quick sort
func find_kth(a *[maxn]int, l, r, k int) int {
	if l >= r {
		return a[l]
	}

	x := a[(l+r)>>1]
	i, j := l-1, r+1

	for i < j {
		for ok := true; ok; ok = (a[i] < x) {
			i++
		}
		for ok := true; ok; ok = (a[j] > x) {
			j--
		}
		if i < j {
			a[i], a[j] = a[j], a[i]
		}
	}

	// j, j+1
	if k <= j {
		return find_kth(a, l, j, k)
	} else {
		return find_kth(a, j+1, r, k)
	}
}

func main() {
	fmt.Scanf("%d %d", &n, &k)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	kth := find_kth(&a, 0, n-1, k-1)
	fmt.Println(kth)
}
