/*----------------------------------------------------------------
 *
 *   文件名称：01-Bash-Game-sg.cpp
 *   创建日期：2021年03月19日 ---- 10时17分
 *   题    目：hdu1846
 *   算    法：sg函数
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 1005;
int n; //石子数量
int m; //一次最多可拿多少石子
int sg[maxn];
int st[maxn]; //后继结点

void SG() {
    memset(sg, 0, sizeof(sg));
    for (int i = 1; i <= n; ++i) {
        memset(st, 0, sizeof(st));
        for (int j = 1; j <= m && i-j >= 0; ++j)
            st[sg[i-j]] = 1;  //把i的后继结点(i-1, i-2, i-3, ... , i-j)放到集合st中
        for (int j = 0; j <= n; ++j)  //计算sg[i]
            if (!st[j]) {
                sg[i] = j;
                break;
            }
    }
}

int main() {
    int c;
    scanf("%d", &c);
    while (c--) {
        scanf("%d %d", &n, &m);
        SG();
        /*sg != 0 先手胜；sg == 0 后手胜*/
        /*if sg != 0 胜*/
        sg[n] ? printf("first\n") : printf("second\n");
    }
    return 0;
}
