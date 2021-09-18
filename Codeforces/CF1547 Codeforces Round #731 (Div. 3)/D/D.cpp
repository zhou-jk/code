#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int a[N],b[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    fill(b+1,b+n+1,0);
    for(int k=0;k<30;k++)
    {
        static int va[N],vb[N];
        for(int i=1;i<=n;i++)
            va[i]=(a[i]>>k)&1,vb[i]=-1;
        for(int i=1;i<=n;i++)
        {
            if(vb[i]==-1) vb[i]=0;
            if(va[i]^vb[i]) vb[i+1]=va[i+1]^1;
        }
        for(int i=1;i<=n;i++)
            b[i]+=(1<<k)*vb[i];
    }
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
    printf("\n");
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}
