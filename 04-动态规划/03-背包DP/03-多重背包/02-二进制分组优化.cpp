/*----------------------------------------------------------------
 *
 *   文件名称：01-二进制分组优化.cpp
 *   创建日期：2021年03月30日 ---- 20时05分
 *   题    目：hdu2191 悼念512汶川大地震
 *   算    法：多重背包
 *   描    述：输入数据首先包含一个正整数t，表示有t组测试用例
 *      每组测试用例第一行是两个整数V和N(1 <= V <= 100, 1 <= N <= 100)
 *      分别表示背包的容量和大米的种类，然后是m行数据
 *      每行包含3个数vo，va和a(1 <= vo <= 20, 1 <= va <= 200, 1 <= a <= 20)
 *      分别表示大米的体积、每袋的价值以及对应种类大米的袋数
 *      输出能够购买的大米的最大价值(题意有更改)
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
//虽然题目的N <= 100，但二进制分组后会变多，所以需要更多存储空间
const int maxn = 1005;
struct Bone {
    int vol;
    int val;
} bone[maxn];
int N, V;
int dp[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &V, &N);
        int idx = 1; //拆分后物品总数
        for (int i = 1; i <= N; ++i) {
            int vo, va, a; //体积，价值，大米袋数
            scanf("%d %d %d", &vo, &va, &a);
            int b = 1;     //二进制分组优化，1, 2, 4, 8, 16, ...
            while (a - b > 0) {
                a -= b;
                bone[idx].vol = b * vo;
                bone[idx].val = b * va;
                ++idx;
                b *= 2;
            }
            bone[idx].vol = a * vo; //补充不足指数的差值
            bone[idx].val = a * va;
            ++idx;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < idx; ++i) //对拆分后的物品进行0-1背包
            for (int j = V; j >= bone[i].vol; --j)
                dp[j] = max(dp[j], dp[j-bone[i].vol] + bone[i].val);
        printf("%d\n", dp[V]);
    }
    return 0;
}
