/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月11日 ---- 15时10分
 *   题    目：AcWing 92 递归实现指数型枚举
 *   算    法：递归
 *   描    述：从1~n这n(n < 20)个整数中随机选取任意多个，输出所有可能的选择方案
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;
vector<int> chosen;
int n;

//对于第x个数做出选择
void calc(int x) {
    if (x == n + 1) {
        for (int i = 0; i < chosen.size(); ++i)
            printf("%d ", chosen[i]);
        puts("");
        return ;
    }
    calc(x + 1); //没有选择x的分支
    chosen.push_back(x); //选择x
    calc(x + 1); //选择x的分支
    chosen.pop_back(); //回溯
}

int main() {
    scanf("%d", &n);
    calc(1);
    return 0;
}
