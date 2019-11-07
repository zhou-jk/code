#include<iostream>  
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MOD=1000000007;
int n,m,K,S;
long long f[200005][30];
long long fac[200005],inv[200005];
int A[30];
long long ans;
struct Node
{
    int x,y;
}a[200005];
bool cmp(Node a,Node b)
{
    return a.x+a.y<b.x+b.y;
}
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
void init(int k)
{
    fac[0]=1;
    for(int i=1;i<=k;i++)
        fac[i]=fac[i-1]*i%MOD;
    inv[0]=1;
    inv[k]=ksm(fac[k],MOD-2);
    for(int i=k-1;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}
long long C(int n,int m)
{
    if(m==0||m==n) return 1;
    if(n<m) return 0;
    return fac[n]*inv[m]%MOD*inv[n-m]%MOD; 
}
int ways(int i,int j)
{
    return C(a[j].x+a[j].y-a[i].x-a[i].y,a[j].x-a[i].x);
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&K,&S);
    int lg=log2(S);
    A[0]=S;
    for(int i=1;i<=lg;i++)
        S=(S+1)/2,A[i]=S;
    init(n+m);
    for(int i=1;i<=K;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    K++,a[K].x=n,a[K].y=m;
    sort(a+1,a+K+1,cmp);    
    for(int i=1;i<=K;i++)
        for(int j=0;j<=lg;j++)
        {
            f[i][j]=C(a[i].x+a[i].y-2,a[i].x-1);
            for(int k=1;k<i;k++)
                if(a[k].x<=a[i].x&&a[k].y<=a[i].y) f[i][j]=(f[i][j]-f[k][j]*ways(k,i)+MOD)%MOD;
            for(int k=0;k<j;k++)
                f[i][j]=(f[i][j]-f[i][k]+MOD)%MOD;
        }
    long long sum=C(n+m-2,n-1);
    for(int i=0;i<=lg;i++)
        ans=(ans+f[K][i]*A[i])%MOD,sum=(sum-f[K][i]+MOD)%MOD;
    ans=(ans+sum)%MOD; 
    ans=ans*ksm(C(n+m-2,n-1),MOD-2)%MOD;
    printf("%lld",ans);
    return 0;
}