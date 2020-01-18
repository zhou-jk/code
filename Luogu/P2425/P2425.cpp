#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=51;
long long C[N][N],ans;
char s[N];
int n;
int f[10];
int a[N];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
        a[i]=s[i]-'0';
    C[0][0]=1;
    for(int i=1;i<=n;i++)
        C[i][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    for(int i=1;i<=n;i++)
        f[a[i]]++;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<a[i];j++)
            if(f[j]>=1)
            {
                f[j]--;
                long long ret=1;
                for(int k=1,p=n-i;k<=9;k++)
                    ret*=C[p][f[k]],p-=f[k];
                ans+=ret;
                f[j]++;
            }
        f[a[i]]--;
    }
    printf("%lld",ans);
    return 0;
}