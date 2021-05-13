#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(a[1]==a[2])
    {
        for(int i=3;i<=n;i++)
            if(a[i]!=a[1])
            {
                printf("%d\n",i);
                return;
            }
    }
    else
    {
        if(a[3]==a[1]) printf("2\n");
        else printf("1\n");
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