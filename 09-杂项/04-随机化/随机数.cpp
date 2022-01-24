#include <cstdio>
#include <cstdlib> //srand() rand()
#include <ctime>   //time() time是C语言获取当前系统时间的函数，以秒作单位，代表当前时间自Unix标准时间戳(1970年1月1日0点0分0秒，GMT)经过了多少秒。
#define MAXNUM 20000   //MAXNUM/MINNUM是随机数范围
#define MINNUM 10000.0 //MINNUM是随机数保留到小数点后多少位
using namespace std;
int main() {
    srand(time(0)) ; //可以srand(10000*time(0)) 否则直接输出的随机数接近，
    for(int i=0;i<10;i++)
        printf("%f\n", (rand()%MAXNUM)/MINNUM);
    return 0;
}

/*
 * 编译运行后产生十个随机数，然后再次编辑运行产生的数还是这十个，如要改变，需使用srand()函数
 * 产生的随机数范围是0~RAND_MAX，即0~2147483647 ，RAND_MAX定义在<cstdlib>中
 * # define    NUMMOD  20000
 * # define    NUMDEV  10000.0
 * cout<<(rand()%NUMMOD)/NUMDEV<<endl;
 * NUMMOD 决定生成随机数的值的范围，NUMDEV 决定取余后生成的小数的范围
 */
