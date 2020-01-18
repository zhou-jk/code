#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=101;
char s[N];
int n;
int f[N][N];
bool check(int l,int r,int len)
{
    for(int i=1;i<=len;i++)
        for(int j=l+i-1;j+len<=r;j+=len)
            if(s[j]!=s[j+len]) return false;
    return true;
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
        f[i][i]=1;
    for(int i=n;i>0;i--)
        for(int j=i+1;j<=n;j++)
        {
            f[i][j]=j-i+1;
            for(int k=i;k<=j;k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            for(int k=1;k<=j-i+1;k++)
                if((j-i+1)%k==0&&check(i,j,k))
                {
                    if((j-i+1)/k<10) f[i][j]=min(f[i][j],f[i][i+k-1]+3);
                    else if((j-i+1)/k<100) f[i][j]=min(f[i][j],f[i][i+k-1]+4);
                    else f[i][j]=min(f[i][j],f[i][i+k-1]+5);
                }
        }
    printf("%d",f[1][n]);
    return 0;
}