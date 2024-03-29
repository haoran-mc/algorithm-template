/*除了十进制的数用一个int型变量直接存储之外，其他进制的数都用vector容器存储*/
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
// B：bit 二进制
// T：ternary 三进制
// Q：quaternary 四进制
// O：octonary 八进制
// D：decimal 十进制
// H：hexadecimal 十六进制

// 将一个P进制的数转换为D进制的数
int anytoD(vector<int> num_P, int base_P) {
    int num_D  = 0;
    for (int i = 0; i < (int)num_P.size(); ++i)
        num_D += (num_P[i] * pow(base_P, i));
    return num_D;
}

// 将一个D进制的数转换为C进制的数
vector<int> numto;
void Dtoany(int num_D, int base_C) {
    do {
        numto.push_back(num_D % base_C);
        num_D /= base_C;
    }while (num_D != 0);
}

int main() {
    int num = 101110011;
    int base_P = 2;
    vector<int> num_P;
    while (num) {
        num_P.push_back(num % 10);
        num /= 10;
    }
    int base_C = 8;
    int num_D = anytoD(num_P, base_P);
    Dtoany(num_D, base_C);
    for (auto it = numto.end()-1; it != numto.begin()-1; --it)
        printf("%d", *it);
    return 0;
}
