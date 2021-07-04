/*----------------------------------------------------------------
 *
 *   文件名称：进制转换.cpp
 *   创建日期：2020年08月10日
 *   描    述：板子
 *
----------------------------------------------------------------*/

//将其他进制的数转换为十进制
#include <cstdio>

/**
 * 一个函数，将一个字符串转化为十进制数
 * 这里不知道数字字符个数,有大小写字母
 * 12345
 * 1 * 10 + 2
 * 12 * 10 + 3
 * 123 * 10 + 4
 * 1234 * 10 + 5
 * .....
 */
int Conversion(char str[], int len) {
    int unit = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            unit = 62 * unit + (str[i] - 'A');
        else if (str[i] >= 'a' && str[i] <= 'z')
            unit = 62 * unit + (str[i] - 'a') + 26;
        else
            unit = 62 * unit + (str[i] - '0') + 52;
    }
    return unit;
}

int main()
{
    char str[] = "BCD";
    int unit = Conversion(str, 3);
    printf("%d\n", unit);
    return 0;
}
