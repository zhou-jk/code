#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=300005;
int n,m;
char s[N];
int l[N],r[N];
int suf[N][10];
void solve()
{
    scanf("%s",s+1);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%1d",&l[i]);
    for(int i=1;i<=m;i++)
        scanf("%1d",&r[i]);
    n=strlen(s+1);
    for(int j=0;j<=9;j++)
        suf[n+1][j]=n+1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=9;j++)
            suf[i][j]=suf[i+1][j];
        suf[i][s[i]-'0']=i;
    }
    int now=0;
    for(int i=1;i<=m;i++)
    {
        int nxt=-1;
        for(int j=l[i];j<=r[i];j++)
            nxt=max(nxt,suf[now+1][j]);
        if(nxt>n)
        {
            printf("YES\n");
            return;
        }
        now=nxt;
    }
    printf("NO\n");
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