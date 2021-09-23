#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str1 = "ababababababab";
    string str2 = "a";
    int pos = 0;
    vector<int> vec;

    printf("%d %d\n", (int)string::npos, (int)str1.length());

    while (pos != (int)string::npos && pos < (int)str1.length()) {
        pos = str1.find(str2, pos+1);
        if (pos != (int)string::npos)
            vec.push_back(pos);
    }
    for (int i = 0; i < (int)vec.size(); i++)
        printf("%d\n", vec[i]);

    return 0;
}
