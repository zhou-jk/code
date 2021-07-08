#include<iostream>
#include<cstdio>
using namespace std;
int T;
int n,a,b;
void solve()
{
    scanf("%d%d%d",&n,&a,&b);
    if(a==1)
    {
        if((n-1)%b==0) printf("Yes\n");
        else printf("No\n");
        return;
    }
    for(long long i=1;i<=n;i*=a)
    {
        int j=n-i;
        if(j%b==0)
        {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}