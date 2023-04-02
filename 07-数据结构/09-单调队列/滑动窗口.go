/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 22/03/2023 March 18:15:21 CST
 * algorithm:
 * description:
 */

package main

import (
	"bufio"
	"fmt"
	"os"
)

const maxn int = 1e6 + 5

var n, k int
var a, q [maxn]int

// 队列：从队尾进入，队头离开
// hh ↙ tt
func get_min() {
	var hh, tt int = 0, -1
	for i := 0; i < n; i++ {
		if hh <= tt && q[hh] < i-k+1 {
			hh++
		}
		for hh <= tt && a[q[tt]] >= a[i] {
			tt--
		}
		tt++
		q[tt] = i
		if i >= k-1 {
			fmt.Printf("%d ", a[q[hh]])
		}
	}
}

// hh ↖ tt
func get_max() {
	var hh, tt int = 0, -1
	for i := 0; i < n; i++ {
		if hh <= tt && q[hh] < i-k+1 {
			hh++
		}
		for hh <= tt && a[i] >= a[q[tt]] {
			tt--
		}
		tt++
		q[tt] = i
		if i >= k-1 {
			fmt.Printf("%d ", a[q[hh]])
		}
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	fmt.Fscan(in, &n, &k)
	// fmt.Scanf("%d %d", &n, &k)
	for i := 0; i < n; i++ {
		// fmt.Scanf("%d", &a[i])
		fmt.Fscan(in, &a[i])
	}
	get_min()
	fmt.Println()
	get_max()
}
