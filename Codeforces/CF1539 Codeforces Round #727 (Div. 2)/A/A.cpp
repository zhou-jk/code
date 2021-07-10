#include<iostream>
#include<cstdio>
using namespace std;
int T;
int n,x,t;
void solve()
{
    scanf("%d%d%d",&n,&x,&t);
    if(x>t)
    {
        printf("0\n");
        return;
    }
    int v=t/x;
    if(v>n)
    {
        printf("%lld\n",(long long)(n-1)*n/2);
        return;
    }
    long long ans=(long long)v*(n-v)+(long long)(v-1)*v/2;
    printf("%lld\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}