/*----------------------------------------------------------------
 *   
 *   文件名称：01-全排列.cpp
 *   创建日期：2021年05月12日 星期三 13时44分31秒
 *   题    目：<++>
 *   算    法：递归
 *   描    述：可以使用状态压缩
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#define NEXTLINE puts("");
const int maxn = 11;
int n, site[maxn], haxh[maxn];


void DFS(int idx) {
    if (idx > n) {
        for (int i = 1; i <= n; ++i)
            printf("%d", site[i]);
        NEXTLINE; 
        return ;
    }
    // 这里for中的i是具体的数，数1，数2，数3，是这三个数全排列
    for (int i = 1; i <= n; ++i) {
        if (!haxh[i]) {
            site[idx] = i;    //存储全排列
            haxh[i] = true;   //深度优先搜索的两个分支
            //每进一层，idx++
            //递归的深度，每一层深度里填入对应的site[idx]
            DFS(idx + 1);     //深度优先搜索
            haxh[i] = false;  //深度优先搜索的另一个分支
        }
        //下面这个右括号，会阻隔部分返回上一层的idx
    }

}

int main() {
    n = 3;
    DFS(1);
    return 0;
}
