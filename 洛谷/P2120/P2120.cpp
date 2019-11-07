#include<iostream>
#include<cstdio>
using namespace std;
int n;
int X[1000001],P[1000001],C[1000001];
int q[1000001],head=1,tail=1;
long long f[1000001],s[1000001],sp[1000001];
long long calc(int x,int y)
{
    return ((f[x]-f[y])+(s[x]-s[y]))/(sp[x]-sp[y]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&X[i],&P[i],&C[i]);
        s[i]=s[i-1]+(long long)X[i]*P[i],sp[i]=sp[i-1]+P[i];
    }
    for(int i=1;i<=n;i++)
    {
        while(head<tail&&calc(q[head+1],q[head])<X[i])
            head++;
        f[i]=f[q[head]]+X[i]*(sp[i]-sp[q[head]])-(s[i]-s[q[head]])+C[i];
        while(head<tail&&calc(q[tail],q[tail-1])>calc(i,q[tail]))
            tail--;
        q[++tail]=i;
    }
    printf("%lld",f[n]);
    return 0;
}