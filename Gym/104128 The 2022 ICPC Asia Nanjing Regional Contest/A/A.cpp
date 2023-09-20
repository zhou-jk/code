#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1005,L=1000005;
int n,m,k;
int len;
char s[L];
int a[N+N][N+N],sum[N+N][N+N];
int getsum(int l1,int r1,int l2,int r2)
{
    l1=max(l1,1),r1=max(r1,1),l1=min(l1,n+n+1),r1=min(r1,m+m+1);
    l2=max(l2,0),r2=max(r2,0),l2=min(l2,n+n),r2=min(r2,m+m);
    return sum[l2][r2]-sum[l1-1][r2]-sum[l2][r1-1]+sum[l1-1][r1-1];
}
void solve()
{
    cin>>n>>m>>k;
    string str;
    cin>>str;
    len=str.size();
    for(int i=1;i<=len;i++)
        s[i]=str[i-1];
    int u=1,d=n,l=1,r=m;
    int curu=1,curd=n,curl=1,curr=m;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='U') curu++,curd++;
        else if(s[i]=='D') curu--,curd--;
        else if(s[i]=='L') curl++,curr++;
        else if(s[i]=='R') curr--,curl--;
        u=max(u,curu),d=min(d,curd),l=max(l,curl),r=min(r,curr);
    }
    if(u>d||l>r)
    {
        if(k==0) cout<<n*m<<"\n";
        else cout<<0<<"\n";
        return;
    }
    for(int i=1;i<=n+n;i++)
        for(int j=1;j<=m+m;j++)
            a[i][j]=0;
    int curx=0,cury=0;
    a[n][m]=1;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='U') curx++;
        else if(s[i]=='D') curx--;
        else if(s[i]=='L') cury++;
        else if(s[i]=='R') cury--;
        if(abs(curx)<n&&abs(cury)<m) a[curx+n][cury+m]=1;
    }
    for(int i=1;i<=n+n;i++)
        for(int j=1;j<=m+m;j++)
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(getsum(n-(i-u),m-(j-l),n+(d-i),m+(r-j))==(d-u+1)*(r-l+1)-k) ans++;
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}