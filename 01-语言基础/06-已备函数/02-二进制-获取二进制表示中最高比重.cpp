// 创建日期：2021年11月13日 星期六 18时35分45秒
#include <cstdio>
#include <vector>
#define lowbit(x) ((x) & -(x)) // lowbit(ob0100) = 4
#define NEXTLINE puts("");

int getmaxproportion(int num) {
    int b = 1, last = 0, pos = 0;
    while (num) {
        if (num & b) {
            last = b;
            num -= b;
        }
        b <<= 1;
        pos ++ ;
    }
    return pos;
}

void outputbinary(int num) {
    std::vector<int> vec;
    while (num) {
        vec.push_back(num % 2);
        num /= 2;
    }
    for (int i = (int)vec.size() - 1; i >= 0; -- i)
        printf("%d", vec[i]);
    NEXTLINE;
}

int main() {
    for (int i = 1; i < 20; ++ i) {
            printf("%2d %d ", i, getmaxproportion(i));
        outputbinary(i);
    }
    return 0;
}
