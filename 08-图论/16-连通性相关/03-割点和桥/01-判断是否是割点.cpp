/*----------------------------------------------------------------
 *
 *   文件名称：01-判断是否是割点.cpp
 *   创建日期：2021年03月24日 ---- 20时51分
 *   题    目：poj1144 network
 *   算    法：割点
 *   描    述：输入一个无向图，求割点的数量
 *      使用深搜优先生成树求割点
 *      定义num[u]记录DFS对每个点的访问顺序，num值随着递推深度增加
 *      而变大
 *      定义low[v]记录v和u的后代能连回到的祖先的num
 *      只要low[v] >= num[u]，就说明在v这个支路上没有回退边连回u的
 *      祖先，最多退到u本身
 *      把程序中的if (low[v] >= num[u] && u != 1) 改为 if (low[v] > num[u] && u != 1)
 *      其他程序不变，就是求割边的数量
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 109;
int low[maxn];
int num[maxn];
int dfn; //时间戳，记录进入递归的顺序
bool iscut[maxn]; //标记是否为割点
vector <int> g[maxn];

void dfs(int u, int fa) {     //u的父结点是fa
    low[u] = num[u] = ++dfn;  //初始值
    int child = 0;            //孩子数目
    for (int i = 0; i < g[u].size(); ++i) { //处理u的所有子结点
        int v = g[u][i];
        if (!num[v]) {        //v没访问过
            child++;
            dfs(v, u);
            low[u] = min(low[v], low[u]);  //用后代的返回值更新low值
            if (low[v] >= num[u] && u !=1)
                iscut[u] = true;           //标记割点
        }
        else if (num[v] < num[u] && v != fa)
            //处理回退边，注意这里v != fa，fa是u的父结点，
            //fa也是u的邻居，但是前面已经访问过，不需要处理它
            low[u] = min(low[u], num[v]);
    }
    if (u == 1 && child >= 2) //根结点，有两个以上不相连的子树
        iscut[1] = true;
}

/*根结点从1开始*/
int main() {
    int res;
    int n;
    while (scanf("%d", &n) != -1) {
        if (n == 0)
            break;
        memset(low, 0, sizeof(low));
        memset(num, 0, sizeof(num));
        dfn = 0;
        for (int i = 0; i <= n; ++i)
            g[i].clear();
        int ver1, ver2;
        while (scanf("%d", &ver1) && ver1)
            while (getchar() != '\n') {
                scanf("%d", &ver2);
                g[ver1].push_back(ver2);
                g[ver2].push_back(ver1);
            }
        memset(iscut, false, sizeof(iscut));
        res = 0;
        dfs(1, 1);
        for (int i = 1; i <= n; ++i)
            res += iscut[i];
        printf("%d\n", res);
    }
    return 0;
}
