// 创建日期：2021年11月01日 星期一 09时11分42秒
#include <cstdio>
#include <vector>
#define NEXTLINE puts("");
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
    for (int i = 1; i < 20; ++ i)
        outputbinary(i);
    return 0;
}
