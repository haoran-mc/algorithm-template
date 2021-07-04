#include <stdio.h>

//寻找木棍中的最长木棍
int max_length(int stick[], int n) {
    int max = stick[0];
    for (int i = 0; i < n; i++)
        if (stick[i] > max)
            max = stick[i];
    return max;
}

//计算出当截mid长度的木棍时会得到多少根
int calculate(int stick[], int mid, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += stick[i] / mid;

    return sum;
}

int numStick(int stick[], int sum, int n) {
    //目的是找到最长的的长度
    int left  = 0;
    int right = max_length(stick, n);
    int mid;

    //当左右边界相等是，还可以循环
    //这里的结束条件需要配合下面的if else分支结构共同停止
    //为什么这里要用 " = " ? 因为后面不停地 左右边界 = mid + 1
    //所以一定会使 left = right 而当 left == right 时仍可循环，mid = left = right，也就是要得到的长度
    while (left <= right) {
        printf("%d %d\n", left, right);
        //左右边界相等时，mid不变
        mid = (left + right) / 2;
        if (calculate(stick, mid, n) > sum)
            left  = mid + 1;

        else
            right = mid - 1;
    }
    return mid;
}

int main() {
    int n = 3;
    int sum = 7;
    int stick[] = {10, 24, 15};
    printf("%d\n", numStick(stick, sum, n));
    return 0;
}
