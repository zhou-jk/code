//AC
#include <cstdio>

int akm(int m,int n)
{
    if (!m) return n+1;
    if (!n) return akm(m-1,1);
    return akm(m-1,akm(m,n-1));
}

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d",akm(m,n));
    return 0;
}