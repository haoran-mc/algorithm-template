/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 01/04/2023 April 23:04:46 CST
 * question:
 * algorithm:
 * description:
 */

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const base uint = 131
const maxn int = 2e6 + 5

var p [maxn]uint      // 2^64-1
var h1, h2 [maxn]uint // 前缀、后缀子字符串哈希

// |---------------------------|
//      ↑        ↑
//      i        j

func main() {
	var str string
	var t int = 0
	for {
		str = rnS()
		if str == "END" {
			break
		}

		// 1. 字符串扩展为奇数串
		str = expand(str)

		// 2. 计算前缀哈希
		n := len(str) - 1 // [1, n]
		p[0] = 1
		for i := 1; i <= n; i++ {
			// |--- i ------- j ---|
			j := n - i + 1 // 对称位置
			h1[i] = h1[i-1]*base + uint(str[i]-'a'+1)
			h2[i] = h2[i-1]*base + uint(str[j]-'a'+1)
			p[i] = p[i-1] * base
		}

		// 3. 枚举中点，二分半径
		res := 0
		for i := 1; i <= n; i++ {
			l, r := 0, min(i-1, n-i)
			for l < r {
				mid := (l + r + 1) / 2
				if get(h1, i-mid, i-1) != get(h2, n-(i+mid)+1, n-(i+1)+1) {
					r = mid - 1
				} else {
					l = mid
				}
			}

			// 找到最大的回文串半径是 l
			res = max(res, l)
		}
		t++
		fmt.Printf("Case %d: %d\n", t, res)
		// fmt.Fprintf(ot, "Case %d: %d\n", t, res)
	}
}

func get(h [maxn]uint, l, r int) uint {
	// |--------------------|
	//      ↑    ↑
	return h[r] - h[l-1]*p[r-l+1]
}

func expand(str string) string {
	var expand_str string
	expand_str += "#"
	for i := 0; i < len(str); i++ {
		expand_str += string(str[i])
		expand_str += "#"
	}
	expand_str = " " + expand_str
	return expand_str
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// ----------------------------------------------------
var (
	ot = bufio.NewWriter(os.Stdout)
	in = bufio.NewScanner(os.Stdin) // in *buffer.Scanner
	bs = make([]byte, 224)          // 缓冲区容量
)

func init()        { in.Split(bufio.ScanLines); in.Buffer(bs, len(bs)) }
func rnS() string  { in.Scan(); return in.Text() }
func rnI() int     { i, _ := strconv.Atoi(rnS()); return i }
func rnF() float64 { f, _ := strconv.ParseFloat(rnS(), 64); return f }
