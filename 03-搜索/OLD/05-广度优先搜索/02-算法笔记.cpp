/*----------------------------------------------------------------
 *
 *   文件名称：Second.cpp
 *   创建日期：2020年09月10日 ---- 17时37分
 *   题    目：算法笔记
 *             给定一个m*n (m, n < 100)大小的迷宫，其中
 *             * 代表不可通过的墙壁
 *             · 代表平地
 *             S 表示起点
 *             T 代表终点
 *             移动过程中，如果当前位置是(x, y)(下标从0开始)，且
 *             每次只能上下左右移动一个位置
 *             (x, y+1) (x, y-1) (x+1, y) (x-1, y)
 *             求从起点S到达终点T的最小步数
 *             如果无法到达，返回-1
 *   输    入：m  n
 *             * * * * * *
 *             S * * * * *
 *             . . . . . .
 *             * * * * * T
 *             * * * * * *
 *   输    出：7
 *   例      ：
 *             输入：
 *                   . . . . .
 *                   . * . * .
 *                   . * S * .
 *                   . * * * .
 *                   . . . T *
 *             输出：11
 *   算    法：广度优先搜索
 *   描    述：<++>
 *   错    误：- std::begin
 *             - std::stop
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100;

struct Node {
    int x;
    int y;
    int step;
}start, stop, node;
int m;
int n;
char maze[maxn][maxn];
bool inq[maxn][maxn];
int nextX[4] = {0, 0, 1, -1};
int nextY[4] = {1, -1, 0, 0};

//判断(x, y)位置是否有效
bool judge(int x, int y) {
    if (x >= n || x < 0 || y >= m || y < 0)
        return false;
    if (maze[x][y] == '*')
        return false;
    if (inq[x][y] == true)
        return false;
    return true;
}

int BFS() {
    queue<Node> quu;
    quu.push(start);
    while (quu.empty() == false) {
        Node top = quu.front();
        quu.pop();
        if (top.x == stop.x && top.y == stop.y)
            return top.step;

        for (int i = 0; i < 4; i++) {
            int newX = top.x + nextX[i];
            int newY = top.y + nextY[i];
            if (judge(newX, newY) == true) {
                node.x = newX;
                node.y = newY;
                node.step = top.step + 1;
                quu.push(node);
                inq[newX][newY] = true;
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d", &m);
    scanf("%d", &n);
    for (int i = 0; i < m; i++) {
        getchar();
        for (int j = 0; j < n; j++)
            maze[i][j] = getchar();

        maze[i][m+1] = '\0';
    }
    scanf("%d", &start.x);
    scanf("%d", &start.y);
    scanf("%d", &stop.x);
    scanf("%d", &stop.y);
    start.step = 0;
    printf("%d\n", BFS());
    return 0;
}
