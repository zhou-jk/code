#include <cstdio>

int main()
{
    int a=-1;
    unsigned int b=1;
    if (a>b) puts("#0 0"); //a被升级为usigned int
    else puts("#0 1");
    printf("#1 %u\n",(unsigned int)a);//2^32-1
    return 0;
}