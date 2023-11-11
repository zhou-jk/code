#include <stdio.h>
#include <stdlib.h>
void dectobin(int n)
{
    if(n==0)
    {
        printf("0");
        return;
    }
    int s[32];
    int tot=0;
    while(n)
        s[++tot]=n&1,n>>=1;
    for(int i=tot;i>=1;i--)
        printf("%d",s[i]);
    return;
}