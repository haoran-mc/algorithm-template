#include <cstdio>
#define lowbit(x) ((x) & -(x))

int main() {
    printf("%d\n", lowbit(12)); // 1100
    return 0;
}
