/*----------------------------------------------------------------
 * 文件名称：八数码.cpp
 * 创建日期：2021年11月26日 星期五 10时35分46秒
 * 题 目：AcWing 0179 八数码问题
 * 算 法：宽度优先搜索
 * 描 述：<++>
 ----------------------------------------------------------------*/

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
const int dx[] = { 0, -1, 0, 1 };
const int dy[] = { -1, 0, 1, 0 };
const char op[] = "lurd";

string BFS(string start) {
	string over = "12345678x";
	queue<string> q;
	unordered_map<string, pair<string, char>> pre;
	unordered_map<string, bool> used;
	q.push(start);
	used[start] = true;
	while (q.size()) {
		string t = q.front();
		q.pop();
		if (t == over)
			break;
		int x, y;
		for (int i = 0; i < t.size(); ++i)
			if (t[i] == 'x')
				x = i / 3, y = i % 3;
		string source = t;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
				continue;
			swap(t[x * 3 + y], t[nx * 3 + ny]);
			if (!used[t]) {
				used[t] = true;
				q.push(t);
				pre[t] = { source, op[i] };
			}
			swap(t[x * 3 + y], t[nx * 3 + ny]);
		}
	}
	string res;
	while (over != start) {
		res += pre[over].second;
		over = pre[over].first;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	string g, seq, c;
	while (cin >> c) {
		g += c;
		if (c != "x")
			seq += c;
	}
	int cnt = 0;
	for (int i = 0; i < seq.size(); ++i)
		for (int j = i + 1; j < seq.size(); ++j)
			if (seq[i] > seq[j])
				cnt++;
	if (cnt & 1)
		cout << "unsolvable" << endl;
	else
		cout << BFS(g) << endl;
	return 0;
}
