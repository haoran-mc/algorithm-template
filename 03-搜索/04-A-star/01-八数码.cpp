/*----------------------------------------------------------------
 * 文件名称：八数码.cpp
 * 创建日期：2021年11月25日 星期四 11时27分52秒 
 * 题 目：AcWing 0179 八数码 
 * 算 法：astar 直接使用 BFS + cantor 也可以，代码在 
 * 数学 -> 组合数学 -> 康托展开 
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
 * 八数码问题无解当且仅当逆序对数量是奇数。
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
const char op[] = "lurd";
int f(string state) {
    int res = 0;
    for (int i = 0; i < state.size(); ++ i)
        if (state[i] != 'x') {
            int t = state[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    return res;
}
string BFS(string start) {
    string over = "12345678x";
    unordered_map<string, int> dist;
    unordered_map<string, bool> used;
    unordered_map<string, pair<string, char>> prev;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> he;
    he.push({f(start), start});
    dist[start] = 0;
    while (he.size()) {
        auto t = he.top(); he.pop();
        string state = t.second;
        if (state == over)
            break;
        if (used[state])
            continue;
        used[state] = true;
        int step = dist[state];
        int x, y;
        for (int i = 0; i < state.size(); ++ i)
            if (state[i] == 'x')
                x = i / 3, y = i % 3;
        string source = state;
        for (int i = 0; i < 4; ++ i) {
            int nx = x + dx[i],
            ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;
            swap(state[x * 3 + y], state[nx * 3 + ny]);
            if (!dist.count(state) || dist[state] > step + 1) {
                dist[state] = step + 1;
                prev[state] = {source, op[i]};
                he.push({dist[state] + f(state), state});
            }
            swap(state[x * 3 + y], state[nx * 3 + ny]);
        }
    }
    string res;
    while (over != start) {
        res += prev[over].second;
        over = prev[over].first;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    string g, c, seq;
    while (cin >> c) {
        g += c;
        if (c != "x")
            seq += c;
    }
    int t = 0;
    for (int i = 0; i < seq.size(); ++ i)
        for (int j = i + 1; j < seq.size(); ++ j)
            if (seq[i] > seq[j])
                t ++ ;
    if (t & 1)
        cout << "unsolvable" << endl;
    else
        cout << BFS(g) << endl;
    return 0;
}
