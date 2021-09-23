/*----------------------------------------------------------------
 *   
 *   文件名称：对顶堆.cpp
 *   创建日期：2021年06月02日 星期三 22时21分50秒
 *   题    目：AcWing 0106 动态中位数
 *   算    法：对顶堆
 *   描    述：维护一个动态中位数
 *          一般堆用he(heap)表示，大根堆用hE表示
 *          哈希用ha(hash)表示
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define NEXTLINE puts("");

int main() {
    // t组数，m是各组编号，n是各组数据个数
    int t, m, n;
    scanf("%d", &t);
    while (t--) {
        priority_queue<int> hE; // hE为大根堆
        priority_queue<int, vector<int>, greater<int>> he; // he为小根堆
        scanf("%d %d", &m, &n);
        printf("%d %d\n", m, (n + 1) / 2);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int _;
            scanf("%d", &_);
            he.push(_);
            if (hE.size() && hE.top() > he.top()) {
                int a = he.top(),
                    b = hE.top();
                he.pop(), hE.pop();
                he.push(b), hE.push(a);
            }
            while (he.size() > hE.size()) {
                hE.push(he.top());
                he.pop();
            }
            if (i & 1)//奇数
                printf("%d%c", hE.top(), ++cnt % 10 == 0 ? '\n' : ' ');//每10个数换一行
        }
        if (cnt % 10)
            NEXTLINE
    }
    return 0;
}
