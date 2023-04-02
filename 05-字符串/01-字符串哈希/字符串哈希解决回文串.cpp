/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 01/04/2023 April 00:19:15 CST
 * question: acwing 0139
 * algorithm:
 * description:
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const int maxn = 2e6 + 5;
const int base = 131;
char str[maxn];
ull hl[maxn], hr[maxn], p[maxn];

ull get(ull h[], int l, int r) {
    return h[r] - h[l-1] * p[r-l+1];
}

int main() {
    int t = 1;
    while (scanf("%s", str+1), strcmp(str+1, "END")) {
        int n = strlen(str+1);

        // 1. 扩展为奇字符串
        for (int i = 2*n; i > 0; i -=2) {
            str[i] = str[i / 2];
            str[i - 1] = 'z'+1;
            // _#a#b#c#d#e#f#g 最后不加上一个 # 也可以吗
        }
        n *= 2;

        // 2. 计算前后缀子字符串哈希值
        p[0] = 1;
        for (int i = 1, j = n; i <= n; i++, j--) {
            hl[i] = hl[i-1]*base + str[i]-'a'+1;
            hr[i] = hr[i-1]*base + str[j]-'a'+1;
            p[i] = p[i-1] * base;
        }

        // 3. 枚举中点，二分半径
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int l = 0, r = min(i-1, n-i); // 半径的区间是[l, r]
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (get(hl, i-mid, i-1) != get(hr, n-(i+mid)+1, n-(i+1)+1)) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            if (str[i - l] <= 'z') {
                res = max(res, l + 1);
            } else {
                res = max(res, l);
            }
        }

        printf("Case %d: %d\n", t++, res);
    }
    return 0;
}
