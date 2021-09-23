#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

/*在text中查找子串pattern，sa是text的后缀数组*/
//原字符串中从第sa[0]位置开始的后缀子串在字典序中排列第0
int find(string text, string pattern, int* sa) {
    int i = 0;
    int j = text.length();
    /*而分发查找*/
    while (j - i >= 1) {
        int k = (i + j) / 2;
        if (text.compare(sa[k], pattern.length(), pattern) < 0)
            i = k;
        else
            j = k;
    }
    /*找到了，返回pattern在text中的位置*/
    if (text.compare(sa[j], pattern.length(), pattern) == 0)
        return sa[j];
    return -1;
}

int main() {
    string text = "vamamadn";
    string pattern = "ad";
    int sa[] = {5, 3, 1, 6, 4, 2, 7, 0}; //sa是text的后缀数组，假设已经得到
    int location = find(text, pattern, sa);
    cout << location << ":" << &text[location] << endl << endl;
    return 0;
}
