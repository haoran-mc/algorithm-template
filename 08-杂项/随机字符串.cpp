#include <cstdio>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main() {
    srand(time(0));                         //产生随机化种子
    int n=rand()%15+1;                      //在1-15的范围内随机产生字符串个数
    printf("%d",n);
    while(n--) {                            //依次产生n个字符串
        printf("\n");
        int k=rand()%50+1;                  //随机生成一个字符串的长度
        for(int i=1;i<=k;i++) {
            int x,s;                        //x表示这个字符的ascii码 ，s表示这个字符的大小写
            s=rand()%2;                     //随机使s为1或0，为1就是大写，为0就是小写
            if(s==1)                        //如果s=1
                x=rand()%('Z'-'A'+1)+'A';   //将x赋为大写字母的ascii码 //注意加一
            else
                x=rand()%('z'-'a'+1)+'a';   //如果s=0，x赋为小写字母的ascii码
            printf("%c",x);                 //将x转换为字符输出
        }
    }
    return 0;
}
