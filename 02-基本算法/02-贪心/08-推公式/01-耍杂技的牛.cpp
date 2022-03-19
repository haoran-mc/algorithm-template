/*----------------------------------------------------------------
 * 文件名称：刷杂技的牛.cpp
 * 创建日期：2021年11月03日 星期三 20时33分53秒 
 * 题 目：AcWing 0125 刷杂技的牛 
 * 算 法：贪心 
 * 描 述：奶牛学习叠罗汉 
 * 这 n 头奶牛中的每一头都有着自己的重量 wi 以及自己的强壮程度 si。 
 * 这头牛的头上所有牛的总重量（不包括它自己）减去它的身体强壮程度
 * 的值称为该牛的风险值，风险值越大，这只牛撑不住的可能性越高。
 * 你的任务是确定奶牛的排序，使得所有奶牛的风险值中的最大值尽可能的小。
 *
 * 按 wi + si 从小到大排序
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 5e4 + 5;
const int INF = 0x3f3f3f3f;
PII cows[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        int w, s;
        scanf("%d %d", &w, &s);
        cows[i] = {w + s, w};
    }
    sort(cows, cows + n);
    int sum = 0, res = -INF;
    for (int i = 0; i < n; ++ i) {
        int w = cows[i].second,
            s = cows[i].first - cows[i].second;
        res = max(res, sum - s);
        sum += w;
    }
    printf("%d\n", res);
    return 0;
}
