/*----------------------------------------------------------------
 *
 *   文件名称：模拟退火求函数值.cpp
 *   创建日期：2021年03月07日 ---- 16时06分
 *   题    目：hdu1899
 *   算    法：模拟退火
 *   描    述：函数F(x) = 6x^7 + 8x^6 + 7x^3 + 5x^2 - yx;
 *   x 的范围是0 <= x <= 100
 *   输入y值，输出F(x)最小值
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-8;    //终止温度
double y;
double func(double x) {
    return 6*pow(x, 7.0) + 8*pow(x, 3.0) + 5*pow(x, 2.0) - y*x;
}

double solve() {
    double T = 100;        //初始温度
    double delta = 0.98;   //降温系数
    double x = 10.0;       //x初始值
    double now = func(x);  //计算初始函数值
    double ans = now;      //返回值
    while (T > eps) {      //eps是终止温度
        int f[2] = {1, -1};
        double newx = x + f[rand()%2] * T;  //按概率改变x，随T的降温而减少
        if (newx >= 0 && newx <= 100) {
            double nxt = func(newx);
            ans = min(ans, nxt);
            if (now - nxt > eps)   //更新x
                x = newx, now = nxt;
        }
        T *= delta;
    }
    return ans;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%lf", &y);
        printf("%.4f\n", solve());
    }
    return 0;
}
