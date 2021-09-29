#include<iostream>
#include<cstdio>
#include<cstring>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=6,C=50;
int n,c;
int l[N];
long long f[C*N+1][1<<N];
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++)
        scanf("%d",&l[i]);
    sort(l,l+n,greater<int>());
    static int p[N];
    iota(p,p+n,0);
    long long sum=0;
    do
    {
        memset(f,0,sizeof(f));
        f[l[p[0]]*n][1]=1;
        for(int i=1;i<c*n;i++)
            for(int j=i;j<=c*n;j++)
            {
                int t=i%n;
                for(int s=0;s<(1<<n);s++)
                    if(!(s&(1<<t))) f[min(c*n,max(j,i+l[p[t]]*n))][s|(1<<t)]+=f[j][s];
            }
        sum+=f[c*n][(1<<n)-1];
    }
    while(next_permutation(p+1,p+n));
    double ans=sum;
    for(int i=1;i<n;i++)
        ans/=i;
    for(int i=2;i<=n;i++)
        ans/=c;
    printf("%.16lf",ans);
    return 0;
}