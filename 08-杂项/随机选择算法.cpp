#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 100010;
int num[N];

//随机核心
int randPartition(int num[], int left, int right) {
    int random = (int)(round(1.0 * rand() / RAND_MAX * (right - left) + left));
    swap(num[random], num[left]);
    int temp = num[left];

    while (left < right) {
        while (left < right && num[right] > temp)
            right--;

        num[left] = num[right];

        while (left < right && num[left] <= temp)
            left++;

        num[right] = num[left];
    }
    num[left] = temp;
    return left;
}

//找寻第k大的数
int randSelect(int num[], int left, int right, int k) {
    if (left == right)
        return num[left];

    int p = randPartition(num, left, right);
    int m = p - left + 1;

    if (k == m)
        return num[p];
    else
        return randSelect(num, p + 1, right, k - m);
}

int main() {
    int num[] = {5, 8, 2, 7, 3, 6, 0, 1, 9, 4};
    printf("%d\n", randSelect(num, 0, 9, 6));
    return 0;
}
