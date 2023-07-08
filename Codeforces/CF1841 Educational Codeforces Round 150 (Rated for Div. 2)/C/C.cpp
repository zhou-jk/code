#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=200005;
const int v[5]={1,10,100,1000,10000};
int n;
char s[N];
int a[N];
int num[N][5];
int pre[N][5];
bool book[N];
void solve()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    int cnt[5]={0,0,0,0,0},lst[5]={n+1,n+1,n+1,n+1,n+1};
    long long sum=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<5;j++)
            num[i][j]=0;
        int tot=0,nxt=n+1;
        for(int j=s[i]-'A'+1;j<5;j++)
            if(cnt[j]) tot+=cnt[j],nxt=lst[j];
        if(tot==0) sum+=v[s[i]-'A'],book[i]=true;
        else
        {
            sum-=v[s[i]-'A'],book[i]=false;
            if(tot==1) num[nxt][s[i]-'A']++;
        }
        cnt[s[i]-'A']++,lst[s[i]-'A']=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<5;j++)
            pre[i][j]=pre[i-1][j];
        if(book[i]) pre[i][s[i]-'A']++;
    }
    long long ans=sum;
    int sufmx=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<5;j++)
            if(s[i]-'A'<j)
            {
                long long res=sum;
                for(int k=s[i]-'A';k<j;k++)
                    res-=(long long)pre[i-1][k]*v[k],res+=-(long long)pre[i-1][k]*v[k];
                if(book[i]) res-=v[s[i]-'A'];
                else res+=v[s[i]-'A'];
                if(sufmx>v[j]) res-=v[j];
                else res+=v[j];
                ans=max(ans,res);
            }
            else if(s[i]-'A'>j)
            {
                long long res=sum;
                for(int k=j;k<s[i]-'A';k++)
                    res-=-(long long)num[i][k]*v[k],res+=(long long)num[i][k]*v[k];
                if(book[i]) res-=v[s[i]-'A'];
                else res+=v[s[i]-'A'];
                if(sufmx>v[j]) res-=v[j];
                else res+=v[j];
                ans=max(ans,res);
            }
        sufmx=max(sufmx,v[s[i]-'A']);
    }
    printf("%lld\n",ans);
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