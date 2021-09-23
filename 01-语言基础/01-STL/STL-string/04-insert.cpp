#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string str1 = "ABCDE";
    string str2 = "12345";
    str1.insert(str1.begin()+3, str2.begin()+1, str2.end());
    printf("%s\n", str1.c_str());
    return 0;
}
