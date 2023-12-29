#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=80005,M=100005;
int n,m;
int a[N];
vector<int>pos[M];
int phi[M];
bool isprime[M];
int prime[M],tot;
void init(int n=100000)
{
    fill(isprime+1,isprime+n+1,true);
    isprime[1]=false;
    phi[1]=1;   
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            prime[++tot]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=tot&&i*prime[j]<=n;j++)
        {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }
    return;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    m=*max_element(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pos[a[i]].emplace_back(i);
    long long ans=0;
    for(int d=1;d<=m;d++)
    {
        vector<int>p;
        for(int v=d;v<=m;v+=d)
            p.insert(p.end(),pos[v].begin(),pos[v].end());
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        for(int j=0;j<(int)p.size();j++)
            ans+=(long long)(n-p[j])*phi[d]*j;
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)
        pos[a[i]].clear();
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}