#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n,m;
int u[N],v[N];
int check(int s)
{
    int t=0;
    int res=0;
    for(int i=1;i<=n;i++)
        if(((s>>i)&1)^((t>>i)&1))
        {
            res|=1<<i;
            for(int j=i;j<=n;j+=i)
                t^=1<<j;
        }
    for(int i=1;i<=m;i++)
        if(((res>>u[i])&1)&&!((res>>v[i])&1)) return 0;
    return res;
}
void print(int ans)
{
    vector<int>res;
    for(int l=1;l<=n;l++)
        if((ans>>l)&1) res.emplace_back(l);
    int k=res.size();
    cout<<k<<"\n";
    for(int l:res)
        cout<<l<<" ";
    cout<<"\n";
    return;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i];
    if(n>=20)
    {
        cout<<n<<"\n";
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
        cout<<"\n";
        return;
    }
    if(n/5>=1)
        for(int i=1;i<=n;i++)
        {
            int ans=check(1<<i);
            if(ans) return print(ans);
            if(n/5>=2)
                for(int j=i+1;j<=n;j++)
                {
                    int ans=check((1<<i)|(1<<j));
                    if(ans) return print(ans);
                    if(n/5>=3)
                        for(int k=j+1;k<=n;k++)
                        {
                            int ans=check((1<<i)|(1<<j)|(1<<k));
                            if(ans) return print(ans);
                        }
                }
        }
    cout<<-1<<"\n";
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