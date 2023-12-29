#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
const long long INF=1e18;
int n;
int k[N];
long long l[N],r[N];
vector<long long>a[N],c[N];
long long sumc[N],sumr[N];
long long b[N],tot;
vector<int>pos[N];
void solve()
{
    cin>>n;
    long long L=0,R=0;
    tot=0;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i]>>l[i]>>r[i];
        L+=l[i],R+=r[i];
        a[i].resize(k[i]),c[i].resize(k[i]);
        for(int j=0;j<k[i];j++)
            cin>>a[i][j];
        for(int j=0;j<k[i];j++)
            cin>>c[i][j];
        sumc[i]=0;
        for(int j=0;j<k[i];j++)
            b[++tot]=a[i][j],sumc[i]+=c[i][j];
        sumr[i]=sumr[i-1]+r[i];
    }
    sort(b+1,b+tot+1);
    tot=unique(b+1,b+tot+1)-b-1;
    int s=lower_bound(b+1,b+tot+1,L)-b,t=upper_bound(b+1,b+tot+1,R)-b-1;
    if(t-s+1<R-L+1)
    {
        cout<<0<<"\n";
        return;
    }
    for(int i=1;i<=tot;i++)
        pos[i].clear();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k[i];j++)
            a[i][j]=lower_bound(b+1,b+tot+1,a[i][j])-b,pos[a[i][j]].emplace_back(i);
    }
    long long ans=INF;
    for(int v=s;v<=t;v++)
    {
        long long res=0,ret=b[v];
        ret-=sumr[pos[v].front()-1];
        for(int i=1;i<(int)pos[v].size();i++)
            ret-=sumr[pos[v][i]-1]-sumr[pos[v][i-1]];
        ret-=sumr[n]-sumr[pos[v].back()];
        for(int i:pos[v])
        {
            int j=lower_bound(a[i].begin(),a[i].end(),v)-a[i].begin();
            long long num=min(sumc[i]-c[i][j],r[i]);
            if(num<l[i]) res+=l[i]-num,ret-=l[i];
            else ret-=num;
        }
        if(ret>0) res+=ret;
        ans=min(ans,res);
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