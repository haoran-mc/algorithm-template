/*----------------------------------------------------------------
 * 文件名称：Color-Sequence.cpp
 * 创建日期：2021年10月21日 星期四 09时52分03秒 
 * 题 目：2020 ICPC 江西省大学生程序设计竞赛 
 * 算 法：异或前缀和 
 * 描 述：给定一个颜色序列 
 * 求它有多少个颜色出现次数都是偶数的连续子序列。
 * 颜色数量不超过 20 种
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int color[maxn], preS[maxn];
unordered_map<int, int> ha;

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &color[i]);
        preS[i] = preS[i - 1] ^ (1 << color[i]); // 异或前缀和
    }
    // 现在得到的 preS 数组中存储了一个数
    // 如果这个数的第 i 位是 0，则表明颜色 i 出现了偶数次
    ll res = 0;
    ha[0] = 1; // 这种情况一定是偶数的
    // 找同值前缀和
    // 如果 preS[a] == preS[b]，则 str[a ~ b] 是偶数的
    for (int i = 1; i <= n; ++ i) {
        res += ha[preS[i]];
        ++ ha[preS[i]];
    }
    printf("%lld\n", res);
    return 0;
}
