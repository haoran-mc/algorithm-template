// 创建日期：2021年11月13日 星期六 19时31分00秒
#include <cstdio>
#include <vector>
#define NEXTLINE puts("");
using namespace std;

// 15 拆成 1 + 2 + 4 + 8
vector<int> dividenumtopower2(int num) {
    vector<int> vec;
    int b = 1;
    while (num) {
        if (num & b) {
            vec.push_back(b);
            num -= b;
        }
        b <<= 1;
    }
    return vec;
}

int main() {
    for (int i = 1; i < 20; ++ i) {
        vector<int> vec = dividenumtopower2(i);
        printf("%d:", i);
        for (auto i : vec)
            printf(" %d", i);
        NEXTLINE;
    }
    return 0;
}
