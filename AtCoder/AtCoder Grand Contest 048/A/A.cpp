#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005;
const int INF=1061109567;
int T;
int n;
char s[N];
char t[]={" atcoder`"};
void solve()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    int ans=INF;
    int now=0;
    for(int i=1;i<=min(n,8);i++)
    {
        for(int j=i+1;j<=n;j++)
            if(s[j]>t[i])
            {
                ans=min(ans,now+j-i);
                break;
            }
        if(s[i]<t[i])
        {
            for(int j=i+1;j<=n;j++)
                if(s[j]==t[i])
                {
                    now+=j-i;
                    for(int k=i;k<j;k++)
                        s[k]=s[k+1];
                    s[j]=t[i];
                    break;
                }
            break;
        }
        else if(s[i]>t[i])
        {
            ans=min(ans,now);
            break;
        }
    }
    if(ans>=INF) printf("-1\n");
    else printf("%d\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}