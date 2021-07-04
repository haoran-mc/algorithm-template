/*----------------------------------------------------------------
 *
 *   文件名称：03-wythoff-Game.cpp
 *   创建日期：2021年03月19日 ---- 14时59分
 *   题    目：hdu1527
 *   算    法：博弈论
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double gold = (1 + sqrt(5)) / 2; //黄金分割 = 1.61803398...

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m)) {
        int mini = min(n, m);
        int maxi = max(n, m);
        double k = double(maxi - mini);
        int test = (int)(k * gold);  //乘以黄金分割数，然后取整
        /*test == mini 先手败*/
        test == mini ? printf("0\n") : printf("1\n");
    }
    return 0;
}
