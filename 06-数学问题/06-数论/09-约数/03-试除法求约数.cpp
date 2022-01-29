/*----------------------------------------------------------------
 * 文件名称：01.cpp
 * 创建日期：2021年09月28日 星期二 18时28分47秒 
 * 结束日期：2021年09月28日 星期二 18时37分09秒 
 * 题 目：AcWing 0869 试除法求约数 
 * 算 法：<++>
 * 描 述：给定 n 个正整数 ai，对于每个整数 ai， 
 * 请你按照从小到大的顺序输出它的所有约数。
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define NEXTLINE puts("");
vector<int> get_divisors(int n) {
    vector<int> res;
    for (int i = 1; i <= n / i; ++ i)
        if (n % i == 0) {
            res.push_back(i);
            if (n / i != i)
                res.push_back(n / i);
        }
    sort(res.begin(), res.end());
    return res;
}
int main() {
    int n; scanf("%d", &n);
    while (n --) {
        int a; scanf("%d", &a);
        vector<int> res = get_divisors(a);
        for (auto it = res.begin(); it != res.end(); ++ it)
            printf("%d ", *it);
        NEXTLINE;
    }
    return 0;
}
