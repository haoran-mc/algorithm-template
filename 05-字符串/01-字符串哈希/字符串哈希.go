/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 01/04/2023 April 12:56:48 CST
 * question: acwing 0841
 * algorithm:
 * description:
 * 操作：预处理所有前缀字符串的哈希，如何定义一个字符串的哈希值呢？
 * 把这个字符串看作一个 p 进制的数，将其转化为十进制的数，但是由于
 * 这个字符串可能很长，所以转化为十进制后更长，如何存这个十进制的数
 * 就是一个问题。这时候我们取模，这样我们就能将任意一个字符串映射成
 *  (0 ~ MOD) 之间的一个数了。但是！注意以下几点：
 * 1. 没有字母将会被映射为十进制的数字 0（A, AA, AAA 都会被映射成十
 *    进制的 0），不满足唯一映射（冲突）；
 * 2. 取模操作也可能造成冲突，这里我们使用一个经验值：base = 131 或
 *    者base = 13331，MOD = 2^64，当这样取值的时候，在 99.99% 的情
 *    况下，不会出现冲突，我们认为是唯一映射；
 *
 *                               hash?
 *   [高位]                     <--------->          [低位]
 *   |-------------------------|-----------|--------------|
 *   1                         L           R
 *   ^
 *   |----  哈希数组下标从1开始，ha[1] 表示前 1 个字符串的哈希值
 *
 *   高位：1234，这里 1 在千位，较高！
 *
 *   我们现在已知ha[L-1]，ha[R]
 *
 *   ha[L-1]: 表示下面这个子串的哈希值
 *   |------------------------|
 *   1                      L - 1
 *
 *   ha[R]: 表示下面这个长的子串的哈希值
 *   |-------------------------|-----------|
 *   1                         L           R
 *
 *   让上面的两个串的高位对齐、相减得到我们想要表示出[L, R]区间的哈希值
 *   $hash = ha[R] - ha[L] * p^{R - L + 1};$
 */

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const maxn int = 1e5 + 5

var n, m int
var str string
var base uint = 131 // P 进制数
var ha, p [maxn]uint

// 计算哈希值
func get(l, r int) uint {
	return ha[r] - ha[l-1]*p[r-l+1]
}

func main() {
	// in := bufio.NewReader(os.Stdin)
	// fmt.Fscan(in, &str)

	n := rnI()
	m := rnI()
	str := rnS()
	// fmt.Scanf("%s", &str)
	str = " " + str // 从下标1开始

	p[0] = 1 // base^0 = 1
	for i := 1; i <= n; i++ {
		p[i] = p[i-1] * base                // 会自己溢出，相当于取模
		ha[i] = ha[i-1]*base + uint(str[i]) // 如果有unicode，考虑rune
	}
	for ; m > 0; m-- {
		var l1, r1, l2, r2 int
		// fmt.Scanf("%d %d %d %d", &l1, &r1, &l2, &r2)
		l1 = rnI()
		r1 = rnI()
		l2 = rnI()
		r2 = rnI()
		if get(l1, r1) == get(l2, r2) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

// ----------------------------------------------------
var (
	ot = bufio.NewWriter(os.Stdout)
	in = bufio.NewScanner(os.Stdin) // in *buffer.Scanner
	bs = make([]byte, 20*1024*1024) // 缓冲区容量
)

func init()        { in.Split(bufio.ScanWords); in.Buffer(bs, len(bs)) }
func rnS() string  { in.Scan(); return in.Text() }
func rnI() int     { i, _ := strconv.Atoi(rnS()); return i }
func rnF() float64 { f, _ := strconv.ParseFloat(rnS(), 64); return f }
