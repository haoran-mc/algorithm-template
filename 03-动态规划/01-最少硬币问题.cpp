/*----------------------------------------------------------------
 *
 *   文件名称：最少硬币问题.cpp
 *   创建日期：2021年03月08日 ---- 14时16分
 *   题    目：硬币问题
 *   算    法：动态规划
 *   描    述：有5种硬币，面值分别为1, 5, 10, 25, 50，数量无限，输入非负整数
 *      表示需要付的钱数，要求付钱时选择最少的硬币数
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 251;             //购物需要的钱数不超过250
const int inf  = 0x3f3f3f3f;
int type[5] = {1, 5, 10, 25, 50}; //5种硬币面值
int minCoins[maxn];               //minCoins[i]代表: 付i块钱最少需要多少硬币
#define bug printf("<--->\n");

void solve() {
    for (int i = 0; i < maxn; ++i)  //动态转移方程需要此初始化
        minCoins[i] = inf;
    minCoins[0] = 0;                //初始条件
    for (int i = 0; i < 5; ++i) {
        for (int j = type[i]; j < maxn; ++j)
            minCoins[j] = min(minCoins[j], minCoins[j-type[i]]+1);
    }
}

int main() {
    solve();
    for (int i = 0; i < maxn; ++i)
        printf("minCoins[%d] = %d\n", i, minCoins[i]);
    return 0;
}
