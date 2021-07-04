#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 1e2;
/*int primeFactor[maxn];*/

vector<int> primeFactor;
template<typename T>
void PrimeFactor(T num) {
    for (T i = 2; pow(i, 2) <= num; ++i)
        if (!(num % i)) {
            primeFactor.push_back(i);
            /*primeFactor[cnt++] = i;*/
            while (!(num % i)) num /= i;
        }
    if (num > 1) primeFactor.push_back(num);
    /*primeFactor.clear();*/
}

int main() {
    int num;
    scanf("%d", &num);
    PrimeFactor(num);
    printf("cnt = %d\n", (int)primeFactor.size());
    for (int i = 0; i < (int)primeFactor.size(); ++i)
        printf("%d ", primeFactor[i]);
    return 0;
}
