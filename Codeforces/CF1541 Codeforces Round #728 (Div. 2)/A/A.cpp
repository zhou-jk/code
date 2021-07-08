#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int T;
int n;
void solve()
{
    scanf("%d",&n);
    if(n&1)
    {
        printf("3 1 2 ");
        for(int i=4;i<=n;i+=2)
            printf("%d %d ",i+1,i);
        printf("\n");
    }
    else
    {
        for(int i=1;i<=n;i+=2)
            printf("%d %d ",i+1,i);
        printf("\n");
    }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}