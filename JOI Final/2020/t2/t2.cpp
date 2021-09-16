#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,k;
char s[N];
int prej[N],sufo[N],sufi[N];
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='J')
        {
            q.emplace(i);
            if((int)q.size()>k) q.pop();
        }
        if((int)q.size()==k) prej[i]=q.front();
        else prej[i]=0;
    }
    while(!q.empty()) q.pop();
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='O')
        {
            q.emplace(i);
            if((int)q.size()>k) q.pop();
        }
        if((int)q.size()==k) sufo[i]=q.front();
        else sufo[i]=n+1;
    }
    while(!q.empty()) q.pop();
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='I')
        {
            q.emplace(i);
            if((int)q.size()>k) q.pop();
        }
        if((int)q.size()==k) sufi[i]=q.front();
        else sufi[i]=n+1;
    }
    int ans=INF;
    for(int i=1;i<=n;i++)
    {
        int l=prej[i],r=sufo[i];
        if(l==0||r==n+1) continue;
        r=sufi[r];
        if(r==n+1) continue;
        ans=min(ans,r-l+1-k*3);
    }
    if(ans>=INF) printf("-1");
    else printf("%d",ans);
    return 0;
}