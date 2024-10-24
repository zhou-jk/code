#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=100005;
const int MOD=998244353;
int n;
int a[N];
int s[N];
int c[30][N][2];
int pre[N],suf[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]^a[i];
    for(int j=0;j<30;j++)
    {
        c[j][0][0]=1,c[j][0][1]=0;
        for(int i=1;i<=n;i++)
        {
            c[j][i][0]=c[j][i-1][0],c[j][i][1]=c[j][i-1][1];
            c[j][i][(s[i]>>j)&1]++;
        }
    }
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[s.top()]>a[i]) s.pop();
        if(s.empty()) pre[i]=0;
        else pre[i]=s.top();
        s.emplace(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
        if(s.empty()) suf[i]=n+1;
        else suf[i]=s.top();
        s.emplace(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=pre[i]+1,r=suf[i]-1;
        int sum=0;
        for(int j=0;j<30;j++)
        {
            int cl[2]={c[j][i-1][0],c[j][i-1][1]};
            if(l-2>=0) cl[0]-=c[j][l-2][0],cl[1]-=c[j][l-2][1];
            int cr[2]={c[j][r][0]-c[j][i-1][0],c[j][r][1]-c[j][i-1][1]};
            sum=(sum+((long long)cl[0]*cr[1]+(long long)cl[1]*cr[0])%MOD*(1<<j))%MOD;
        }
        ans=(ans+(long long)sum*a[i])%MOD;
    }
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