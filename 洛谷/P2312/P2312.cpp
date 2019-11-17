#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000001;
const int MOD[5]={22861,22871,22877,22901,22907};
int n,m,a[5][101];
char s[N];
bool vis[5][30001];
int ans[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        scanf("%s",s);
        for(int k=0;k<=4;k++)
            if(s[0]=='-')
            {
                for(int j=1;j<strlen(s);j++)
                    a[k][i]=((a[k][i]<<3)+(a[k][i]<<1)+(s[j]^48))%MOD[k];
                a[k][i]=MOD[k]-a[k][i];
            }
        else 
            for(int j=0;j<strlen(s);j++)
                a[k][i]=((a[k][i]<<3)+(a[k][i]<<1)+(s[j]^48))%MOD[k];
    }
    for(int k=0;k<=4;k++)
        for(int i=1;i<=MOD[k];i++)
        {
            int ans=a[k][n];
            for(int j=n-1;j>=0;j--)
                ans=(ans*i+a[k][j])%MOD[k];
            if(!ans) vis[k][i]=true;
        }
    for(int i=1;i<=m;i++)
    {
        bool flag=true;
        for(int k=0;k<=4;k++)
            flag&=vis[k][i%MOD[k]];
        if(flag) ans[++ans[0]]=i;
    }
    for(int i=0;i<=ans[0];i++)
        printf("%d\n",ans[i]);
    return 0;
}