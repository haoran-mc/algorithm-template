/*----------------------------------------------------------------
 * 文件名称：计数问题.cpp
 * 创建日期：2021年10月31日 星期日 22时03分14秒 
 * 题 目：AcWing 0338 计数问题 
 * 算 法：数位DP
 * 描 述：给定两个整数 a 和 b，求 a 和 b 之间所有数字中 [0, 9]
 * 的出现次数 
 *
 * 例如：a = 1024，b = 1032，则 a 和 b 之间的 9 个数：
 *
 * 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032
 *
 * 其中 0 出现 10 次；1 出现 10 次；2 出现 7 次 ......
 *
 * 0 < a, b < 1e8
 *
 * 多组输入，输入两个 0 结束输入。
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define NEXTLINE puts("");
// 算出前面的数字 abc
int get(vector<int> num, int l, int r) {
    int res = 0;
    for (int i = l; i >= r; -- i)
        res = res * 10 + num[i];
    return res;
}
// 后面还有 x 个数字，10^x
int power10(int x) {
    int res = 1;
    while (x -- )
        res *= 10;
    return res;
}
44
// 从 1 到 n 中 x 出现的次数
int count(int n, int x) {
    if (!n)
        return 0;
    vector<int> num;
    // n 的每一位是什么
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size(); // n 现在是 n 的位数
    int res = 0;
    // 从最高位上开始枚举
    for (int i = n - 1 - !x; i >= 0; -- i) {
        // 只有 i < n - 1 才会出现前面有数，abcdefg
        // ^ 前面要有数字
        if (i < n - 1) {
            res += get(num, n - 1, i + 1) * power10(i);
            if (!x)
                res -= power10(i);
        }
        if (num[i] == x)
            res += get(num, i - 1, 0) + 1;
        else if (num[i] > x)
            res += power10(i);
    }
    return res;
}
int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) && (a || b)) {
        if (a > b)
            swap(a, b);
        for (int i = 0; i < 10; ++ i)
            printf("%d ", count(b, i) - count(a - 1, i));
        NEXTLINE;
    }
    return 0;
}
