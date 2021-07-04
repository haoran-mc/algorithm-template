#include <cstdio>
#include <ctime>
#include <random>
using namespace std;
int main() {
    //std::mt19937 myrand(seed) ，seed可不填，不填seed则会使用默认随机种子
    mt19937 myrand(time(0));
    printf("%ld\n", myrand());
    return 0;
}

