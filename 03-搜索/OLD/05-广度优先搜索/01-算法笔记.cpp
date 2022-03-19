/*----------------------------------------------------------------
 *
 *   文件名称：First.cpp
 *   创建日期：2020年09月10日 ---- 16时25分
 *   题    目：算法笔记
 *             给出一个m*n (m, n < 100)的矩阵，矩阵中的元素为0或1
 *             称位置(x, y)与其上下左右四个位置
 *             (x, y+1) (x, y-1) (x+1, y) (x-1, y)是相邻的
 *             如果矩阵中有若干个1是相邻的(不必两两相邻)，那么称
 *             这些1构成了一个"块"，求给定的矩阵中块的个数
 *   输    入：m  n
 *             1 ... 1
 *             ...
 *             ...
 *             1 ... 1
 *   例      ：
 *             输入：
 *                   6 7
 *                   0 1 1 1 0 0 1
 *                   0 0 1 0 0 0 0
 *                   0 0 0 0 1 0 0
 *                   0 0 0 1 1 1 0
 *                   1 1 1 0 1 0 0
 *                   1 1 1 1 0 0 0
 *             输出：4
 *   算    法：广度优先搜索
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;
struct position {
    int x;
    int y;
}pos;
int m;
int n;
int matrix[maxn][maxn];
bool inq[maxn][maxn];
int nextX[] = {0, 0, 1, -1};
int nextY[] = {1, -1, 0, 0};

bool judge(int x, int y) {
    //越界返回false
    if (x >= n || x < 0 || y >= m || y < 0)
        return false;

    //当前位置是0，或(x, y)已入过队，返回false
    if (matrix[x][y] == 0 || inq[x][y] == true)
        return false;

    //以上都不满足
    return true;
}

//BFS访问位置(x, y)所在的块，将该块内的所有1的inq都设置为true
void BFS(int x, int y) {
    queue<position> quu;
    pos.x = x;
    pos.y = y;
    quu.push(pos);
    inq[x][y] = true;
    //不为空
    while (quu.empty() == false) {
        position top = quu.front(); //取出队首元素
        quu.pop(); //队首元素出队
        for (int i = 0; i < 4; i++) {
            int newX = top.x + nextX[i];
            int newY = top.y + nextY[i];
            if (judge(newX, newY) == true) {
                pos.x = newX;
                pos.y = newY;
                quu.push(pos);
                inq[newX][newY] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &m);
    scanf("%d", &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 1 && inq[i][j] == false)
                (ans++, BFS(i, j));

    printf("%d\n", ans);
    return 0;
}
