/*----------------------------------------------------------------
 *
 * 文件名称：最长上升子序列II.cpp
 * 创建日期：2021年10月25日 星期一 20时09分03秒 
 * 题 目：AcWing 0896 最长上升子序列II
 * 算 法：线性DP
 * 描 述：
 * 给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少 
 *
 * 还要输出这个最长上升子序列
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], // 原序列
    mini[maxn]; // 所有长度下结尾的最小值
const int INF = 0x3f3f3f3f;
int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i)
        scanf("%d", &a[i]);
    int len = 0; // 当前的最大长度
    mini[0] = -INF; // 为了使比当前的数还小的数存在
    for (int i = 0; i < n; ++ i) {
        int l = 0, r = len;
        // 找到在 mini[] 地一个小于 a[i] 的数
        while (l < r) {
            // [l, mid - 1] [mid, r]
            int mid = l + r + 1 >> 1;
            if (mini[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);
        /**
         * 我们二分找到第一个小于 a[i] 的数就是 mini[l] = mini[r]
         * 那么就一定有 a[i] 大于等于 mini[l + 1] = mini[r + 1]
         * 所以更新 mini[r + 1]
         * mini[r + 1] = a[i]
         * 最大长度为 r + 1 的子序列的结尾是 a[i]
         */
        mini[r + 1] = a[i];
    }
    printf("%d\n", len);
    return 0;
}
