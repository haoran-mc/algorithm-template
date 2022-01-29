/*----------------------------------------------------------------
 * 文件名称：魔板.cpp
 * 创建日期：2021年11月24日 星期三 18时03分34秒 
 * 题 目：AcWing 1107 魔板 6 * 算 法：BFS最小步数模型 7 * 描 述：输入 2 * 4 的矩阵，求出经过最少的哪些操作可以使 8 * 初态矩阵 1 2 3 4 转化为输入的矩阵 9 * 8 7 6 5
 * 矩阵的排列就是按上面初态矩阵的排列
 * 比如输入 8 7 6 5 4 3 2 1
 *
 * 那么输入的矩阵就是：
 * 8 7 6 5
 * 1 2 3 4
 *
 * 可以的操作有：
 * A：交换上下两行；
 * B：将最右边的一列插入到最左边；
 * C：魔板中央对的4个数作顺时针旋转。
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int g[2][4];
unordered_map<string, int> dist;
unordered_map<string, pair<char, string>> pre;
queue<string> q;
void set(string str) {
    for (int i = 0; i < 4; ++ i)
        g[0][i] = str[i];
    for (int i = 3, j = 4; i >= 0; -- i, ++ j)
        g[1][i] = str[j];
}
string get() {
    string res;
    for (int i = 0; i < 4; ++ i)
        res += g[0][i];
    for (int i = 3; i >= 0; -- i)
        res += g[1][i];
    return res;
}
string move0(string str) {
    set(str);
    for (int i = 0; i < 4; ++ i)
        swap(g[0][i], g[1][i]);
    return get();
}
string move1(string str) {
    set(str);
    char g03 = g[0][3], g13 = g[1][3];
    for (int i = 3; i > 0; -- i) {
        g[0][i] = g[0][i - 1];
        g[1][i] = g[1][i - 1];
    }
    g[0][0] = g03;
    g[1][0] = g13;
    return get();
}
string move2(string str) {
    set(str);
    char g01 = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = g01;
    return get();
}
void BFS(string start, string end) {
    if (start == end)
        return;
    q.push(start);
    dist[start] = 0;
    while (q.size()) {
        auto t = q.front(); q.pop();
        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);
        for (int i = 0; i < 3; ++ i) {
            string str = m[i];
            if (dist.count(str) == 0) {
                dist[str] = dist[t] + 1;
                pre[str] = {char(i + 'A'), t};
                if (str == end)
                    break;
                q.push(str);
            }
        }
    }
}

int main() {
    int x;
    string start, end;
    for (int i = 0; i < 8; ++ i) {
        cin >> x;
        end += char(x + '0');
    }
    for (int i = 0; i < 8; ++ i)
        start += char(i + '1');
    BFS(start, end);
    cout << dist[end] << endl;
    string res;
    while (end != start) {
        res += pre[end].first;
        end = pre[end].second;
    }
    reverse(res.begin(), res.end());
    if (res.length() > 0)
        cout << res << endl;
    return 0;
}
