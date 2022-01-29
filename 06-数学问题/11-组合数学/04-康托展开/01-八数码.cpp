/*----------------------------------------------------------------
 * 文件名称：八数码.cpp
 * 创建日期：2021年11月25日 星期四 11时27分52秒 
 * 题 目：AcWing 0179 八数码 
 * 算 法：BFS + cantor 也可以使用astar，代码在 搜索 -> A* 
 * 描 述：将输入的一个八数码通过移动 x 来转换为初始八数码 
 * 
 * 1 2 3 1 2 3
 * x 4 6 -> 4 5 6
 * 7 5 8 7 8 x
 *
 * u : 向上
 * d : 向下
 * l : 向左
 * r : 向右
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int grid[10], over[10], n = 9;
int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; // 阶乘
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
// const char conv[] = "lurd";
const char conv[] = "rdlu";
unordered_map<int, int> used;
// 从 pre.second.first 到 pre.first 的变换是 pre.second.second
unordered_map<int, pair<int, char>> pre;
#define NEXTLINE puts("");
#define bug puts("<-->");
/*
 * n 个数，这个 str 不是字符串类型，而是一个数组
 * 里面是 0 - 8 这 9 个数
 * 康托展开公式：res = a[n] * (n - 1)! + a[n - 1] * (n - 2)! + ... + a[1] * 0!;
 * 这里的 a[i] 表示的是第 i 个位置上的数在 i 后面的数中排第几
 */
int Contor(int* sequ, int n) {
    int res = 0;
    for (int i = 0; i < n; ++ i) {
        int cnt = 0;
        for (int j = i + 1; j < n; ++ j)
            if (sequ[i] > sequ[j])
                cnt ++ ;
        res += cnt * fact[n - i - 1];
    }
    return res + 1;
}
// 只能返回 [1, n] 的排列，也容易转换为指定的集合
int* revContor(int ranking, int n) {
    ranking = ranking - 1; // 有 ranking - 1 个排列比目标序列要小
    bool used[10];
    static int permutation[10];
    memset(used, false, sizeof used);
    memset(permutation, -1, sizeof permutation);
    for (int i = 0; i < n; ++ i) {
        int r = ranking / fact[n - i - 1];
        ranking = ranking % fact[n - i - 1];
        for (int j = 1; j <= n; ++ j)
            if (!used[j] && !(r -- )) {
                used[j] = true;
                permutation[i] = j;
                break;
            }
    }
    // sequ 排个序
    // 如果 permutaion[i] = 1，需要指定集合的话，就输出 sequ[permutation[i] - 1];
    return permutation;
}
bool BFS(int rankbegin, int rankover) {
    queue<int> q;
    q.push(rankbegin); // 初始的 Contor 值存入队列中
    used[rankbegin] ++ ;
    while (q.size()) {
        int t = q.front(); q.pop(); // 队顶的 Contor 值
        if (t == rankover)
            return true;
        int *g = revContor(t, n);
        int x, y, idx;
        for (int i = 0; i < 9; ++ i)
            if (g[i] == 9) {
                idx = i;
                // 从 0 开始
                x = i / 3;
                y = i % 3;
                // printf("-- %d %d %d\n", i, x, y);
            }
        /*
         * for (int i = 0; i < 9; ++ i) {
         * printf("%d ", g[i]);
         * if (i == 2 || i == 5 || i == 8)
         * NEXTLINE;
         * }
         */
        for (int i = 0; i < 4; ++ i) {
            int nx = x + dx[i],
            ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;
            int newidx = nx * 3 + ny;
            swap(g[idx], g[newidx]);
            int ranking = Contor(g, n);
            swap(g[idx], g[newidx]);
            if (used.count(ranking))
                continue;
            // printf("-- %d %d %d\n", newidx, nx, ny);
            q.push(ranking);
            pre[ranking] = {t, char(conv[i])};
            used[ranking] ++ ;
        }
        // NEXTLINE;
    }
    return false;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (int i = 0; i < 9; ++ i) {
        char ch[2]; scanf("%s", ch);
        grid[i] = *ch == 'x' ? 9 : (int)(*ch - '0');
    }
    for (int i = 0; i < 9; ++ i)
        over[i] = i + 1;
    int rankover = Contor(over, n); // 结束时的 Contor
    int rankbegin = Contor(grid, n); // 初始的 Contor
    if (BFS(rankover, rankbegin)) {
        while (rankbegin != rankover) {
            char ch = pre[rankbegin].second;
            printf("%c", ch);
            rankbegin = pre[rankbegin].first;
        }
        NEXTLINE;
    }
    else
        puts("unsolvable");
    return 0;
}
