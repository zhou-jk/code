#include <cstdio>

int main()
{
    int a[2]={0,10000};
    int *b=a;
    printf("%d\n",(*b)++); //*先
    printf("%d %d %p\n",a[0],a[1],b);
    printf("%d\n",*b++); //++先
    printf("%d %d %p\n",a[0],a[1],b);
    printf("%d\n",++(*b)); //*先
    printf("%d %d %p\n",a[0],a[1],b);
    printf("%d\n",++*b); //*先 右结合性 b没有增加
    printf("%d %d %p\n",a[0],a[1],b);
    return 0;
}