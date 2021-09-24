#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int A[5] = {0, 1, 2, 3, 4};
    do {
        printf("%d %d %d %d %d\n", A[0], A[1], A[2], A[3], A[4]);
    } while(next_permutation(A, A + 5));

    printf("\n");
    do {
        printf("%d %d %d\n", A[1], A[2], A[3]);
    } while(next_permutation(A + 1, A + 4));

    return 0;
}
