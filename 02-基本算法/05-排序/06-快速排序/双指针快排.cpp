#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
int num[] = {5, 4, 7, 9, 0, 2, 1, 3, 8, 6};

int partition(int left, int right) {
    int random = (int)round(1.0 * rand() / RAND_MAX * (right - left) + left);
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

void quickSort(int left, int right) {
    if (left < right) {
        int mark = partition(left, right);
        quickSort(left, mark - 1);
        quickSort(mark + 1, right);
    }
}

int main() {
    quickSort(0, 9);

    for (int i = 0; i < 10; i++)
        printf("%d ", num[i]);
    printf("\n");

    return 0;
}
