/*----------------------------------------------------------------
 *
 *   文件名称：01-混合背包.cpp
 *   创建日期：2021年04月07日 ---- 17时56分
 *   题    目：AcWing 0007 混合背包问题
 *   算    法：混合背包
 *   描    述：转化为多重背包二进制优化转化为多重背包二进制优化转化为多重背包二进制优化转化为多重背包二进制优化转化为多重背包二进制优化转化为多重背包二进制优化转化为多重背包二进制优化转化为多重背包二进制优化转化为多重背包二进制优化
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int N, V;//物品数量，背包体积转化为多重背包二进制优化
int v[maxn];//体积
int w[maxn];//价值
int dp[maxn];

int main() {
    scanf("%d %d", &N, &V);
    int idx = 1; //拆分后物品总数
    for (int i = 1; i <= N; ++i) {
        int vo, va, a;
        scanf("%d %d %d", &vo, &va, &a);
        int b = 1; //二进制分组优化，1, 2, 4, 8, 16, ...
        //将混合背包转化为多重背包
        if (a < 0)
            a = 1;
        else if (a == 0) //如果是完全背包，则在最优情况下，只能取总体积/该物品体积向下取整
            a = V / vo;
        //如果是a - b > 0，那么下面就不需要if语句判断，直接执行if语句里面的语句
        while (a - b >= 0) {
            a -= b;
            v[idx] = vo * b;
            w[idx] = va * b;
            ++idx;
            b *= 2;
        }
        if (a > 0) {
            v[idx] = a * vo;
            w[idx] = a * va;
            ++idx;
        }
    }
    for (int i = 1; i <= idx; ++i)
        for (int j = V; j >= v[i]; --j)
            dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
    printf("%d\n", dp[V]);
    return 0;
}
