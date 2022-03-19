#include <cstdio>
#include <random>
#include <algorithm>
using namespace std;
int arr[100];

int main() {
    mt19937 myrand(time(0));        //默认随机种子是rand()，这里使用了time(0)
    int n = myrand() % 10 + 10;     //n是(10-19)之间的随机数

    for (int i = 0; i < n; ++i)
        arr[i] = i;
    printf("n = %d\n", n);

    shuffle(arr+3, arr+9, myrand);  //将数组(arr[3] - arr[9])之间的数随机打乱
    for (int i = 0; i < n; ++i) {
        if (i == 3 || i == 9)
            printf("| ");
        printf("%d ", arr[i]);
    }
    printf("\n");
}

