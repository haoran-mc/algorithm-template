/*----------------------------------------------------------------
 * 文件名称：字串变换.cpp
 * 创建日期：2021年11月24日 星期三 22时37分50秒 
 * 题 目：AcWing 0190 字串变换 
 * 算 法：双向搜索 
 * 描 述：<++>
 ----------------------------------------------------------------*/

#include <cstdio>
#include <queue>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 6;
string A, B;
string a[maxn], b[maxn];
int n;
int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db,
        string a[maxn], string b[maxn]) {
    int d = da[q.front()];
    while (q.size() && da[q.front()] == d) {
        auto t = q.front(); q.pop();
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < t.size(); ++ j)
                if (t.substr(j, a[i].size()) == a[i]) {
                    string str = t.substr(0, j) + b[i] + t.substr(j + a[i].size());
                    if (db.count(str))
                        return da[t] + db[str] + 1;
                    if (da.count(str))
                        continue;
                    da[str] = da[t] + 1;
                    q.push(str);
                }
    }
    return 11;
}
int BFS() {
    if (A == B)
        return 0;
    queue<string> qa, qb;
    unordered_map<string, int> da, db;
    qa.push(A), qb.push(B);
    da[A] = db[B] = 0;
    int step = 0;
    while (qa.size() && qb.size()) {
        int t;
        if (qa.size() < qb.size())
            t = extend(qa, da, db, a, b);
        else
            t = extend(qb, db, da, b, a);
        if (t <= 10)
            return t;
        if ( ++ step == 10)
            return -1;
    }
    return -1;
}
int main() {
    cin >> A >> B;
    while (cin >> a[n] >> b[n])
        n ++ ;
    int t = BFS();
    if (t == -1)
        puts("NO ANSWER!");
    else
        cout << t << endl;
    return 0;
}
