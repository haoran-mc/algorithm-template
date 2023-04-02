/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 21/03/2023 March 00:02:25 CST
 * algorithm:
 * description:
 */

package main

import (
	"fmt"
)

const maxn int = 1e5 + 5

var n int
var num [maxn]int

func quickSort(a *[maxn]int, l, r int) {
	if l >= r {
		return
	}

	// 1. 确定分界点：x = a[l], a[(l+r)/2], a[r]
	// 2. 调整区间：|-------- x -------------|
	//                  <= x        >= x
	// 3. 递归处理左右区间
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

	/*
	* 1. 最终 i j 的位置不一定在 x 的位置
	*    i j 的位置取决于 x 的大小，毕竟左侧 <= x；右侧 >= x
	*
	* 2. i j 的位置有两种情况：
	*    要么在同一个位置，要么 j 在 i 前面一个位置
	*
	* 3. 如果 j 在 i 前面一个位置，那么下面两种调用等价
	*    quickSort(a, l, j)        quickSort(a, l, i-1)
	*    quickSort(a, j+1, r)      quickSort(a, i, r)
	*
	* 4. 如果 i j 在同一个位置，那么上面这两种调用就不等价了
	*
	*	 首先，什么时候 i j 同位置？
	*	 数组中只有一个 x，且 x 的位置就应该在 (l+r)/2 的位置
	*
	*    那么上面两种调用可以理解为：将 x 放入左区间还是右区间
	*
	*    假设区间只有两个数，且已排序完毕
	*
	*    由于 x := a[(l+r)>>1]，标兵 x 选择的是第一个数，仅经
	*    过一次 for 循环，i j 就都指向标兵 x，递归调用情况：
	*    quickSort(a, 0, 0)        quickSort(a, 0, -1)
	*    quickSort(a, 1, 1)        quickSort(a, 0, 1)
	*                               ↑ 永远无法跳出递归！
	*
	*    - 当 x := a[(l+r)>>1] 时，应使用第一种调用
	*    - 当 x := a[(l+r+1)>>1] 时，应使用第二种调用
	 */
	quickSort(a, l, j)
	quickSort(a, j+1, r)
}

func main() {
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &num[i])
	}

	quickSort(&num, 0, n-1)

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", num[i])
	}
}
