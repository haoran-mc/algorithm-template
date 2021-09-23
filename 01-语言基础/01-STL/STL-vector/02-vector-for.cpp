#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    for (int &e : vec)
        scanf("%d", &e);
    for (int &e : vec)
        printf("%d ", e);
    printf("\n");
    return 0;
}
