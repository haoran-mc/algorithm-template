/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 30/03/2023 March 16:04:55 CST
 * question: acwing
 * algorithm:
 * description:
 * 我们预想得到一个存储回文串半径的数组 radius[]
 * radius[i] 表示的意义是，以 i 位置为中心，最长
 * 的回文串的半径是多大
 *
 * 1. 将原串转化为奇数串 ^a#b#c#b#a$
 * 2. 在遍历此串时，维护一个右边界最靠右的回文串
 *    |-----------------------------------------|
 *                mid  i  max_r
 *         |-------+-------| 这是已遍历的，以 i 为中心的回文
 *                           串中，右边界 max_r 最大的回文串
 *
 * 我们维护的这个回文串有什么用呢？
 * 当我们需要知道 radius[i] 时，因为回文串的对称性，i 相对于 mid
 * 对称为 j，可以根据 radius[j] 来拓展以 i 为中心的回文串。
 *
 * 根据 radius[j] 拓展以 i 为中心的回文串时，分了四种情况：
 * 2.1 i在维护串的外部，暴力拓展
 * 2.2 i在维护串的内部，串j在维护串内部
 * 2.3 i在维护串的内部，串j超出维护串的左边界
 * 2.4 i在维护串的内部，串j左边界 = 维护串的左边界
 */

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const maxn int = 2e7 + 5

// 维护当前位置最长回文串的半径
// ---+---  radius = 3 不包括中点
var radius [maxn]int

func main() {
	var max_len int
	// var pos int
	var str string

	// fmt.Scanf("%s", &str)

	// in := bufio.NewReader(os.Stdin)
	// fmt.Fscanf(in, "%s", &str)

	str = rnS()
	_, max_len = manacher(str)
	fmt.Println(max_len)
}

// 维护的最右回文子串
type rightmoststr struct {
	mid int // 子串的中点
	r   int // 子串右边界
	l   int // 子串的左边界
}

func manacher(str string) (pos, max_len int) {
	// 1. 将原串转化为奇数串
	str = converse(str)
	ra := []rune(str)

	// 维护的最右回文子串 right most string
	rmstr := rightmoststr{mid: 0, r: 0}

	// 切记不能计算到 $，会有边界问题，除非 ra cap > len
	for i := 1; i < len(ra)-1; i++ {
		j := 2*rmstr.mid - i // i 的对称位置
		if i > rmstr.r {     // 2.1 i在维护串的外部
			radius[i] = 0
			// 没法从维护的最右回文串得到位置 i 的信息
			// 后续需要暴力拓展中心在 i 位置的回文串
		} else {
			/*
				jl := j - radius[j] // j的左边界
				if jl > rmstr.l {   // 2.2 串j左边界在维护串内部
					radius[i] = radius[j]
				} else if jl < rmstr.l { // 2.3 串j左边界在维护串外部
					radius[i] = rmstr.r - i
				} else { // 2.4 串j左边界正好在维护串左边界
					radius[i] = radius[j]
					// 从维护串得到的信息不够
					// 更远的位置可能也是对称的
					// 后续需要暴力拓展中心在 i 位置的回文串
					// 其实这个 radius[j] = 1
				}
			*/
			radius[i] = min(radius[j], rmstr.r-i)
		}
		// 暴力拓展，不需要判断边界，因为 $ 与谁都不配对
		for str[i-radius[i]-1] == str[i+radius[i]+1] {
			radius[i]++
		}
		if i+radius[i] > rmstr.r { // 更新最右回文串
			rmstr = rightmoststr{
				mid: i,
				r:   i + radius[i],
				l:   2*i - (i + radius[i]),
			}
		}
		if radius[i] > max_len {
			max_len = radius[i]
			pos = (rmstr.mid - radius[i]) >> 1
			// 原串的最长回文子串的起点
			// 原串下标从 0 开始
		}
	}
	return pos, max_len
}

/*
 * 这个问题需要注意的边界：
 * 1. 维护的最右回文子串信息：rmstr.r，是开区间还是闭区间
 * 2. radius 数组保存的半径包不包含中点
 */

func converse(str string) string {
	var expand_str string
	expand_str += "^"

	ra := []rune(str)
	expand_str += "#"
	for i := 0; i < len(ra); i++ {
		expand_str += string(ra[i])
		expand_str += "#"
	}

	expand_str += "$"
	return expand_str
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

var (
	ot = bufio.NewWriter(os.Stdout)
	in = bufio.NewScanner(os.Stdin)
	bs = make([]byte, 20*1024*1024) // 缓冲区容量
)

func init()        { in.Split(bufio.ScanWords); in.Buffer(bs, len(bs)) }
func rnS() string  { in.Scan(); return in.Text() }
func rnI() int     { i, _ := strconv.Atoi(rnS()); return i }
func rnF() float64 { f, _ := strconv.ParseFloat(rnS(), 64); return f }
