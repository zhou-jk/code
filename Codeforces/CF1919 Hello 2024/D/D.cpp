#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N];
vector<int>pos[N];
int pre[N],suf[N];
void del(int x)
{
    suf[pre[x]]=suf[x];
    pre[suf[x]]=pre[x];
    return;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        pos[i].clear();
    for(int i=1;i<=n;i++)
        pos[a[i]].emplace_back(i);
    if((int)pos[0].size()>1)
    {
        cout<<"NO\n";
        return;
    }
    for(int i=1;i<=n;i++)
        pre[i]=i-1,suf[i]=i+1;
    for(int l=n-1;l>=1;l--)
    {
        for(int i=0,j=0;i<(int)pos[l].size();i=j)
        {
            while(j+1<(int)pos[l].size()&&pos[l][j+1]==suf[pos[l][j]]) j++;
            int u=pos[l][i],v=pos[l][j];
            if((pre[u]>=1&&a[pre[u]]==a[u]-1)||(suf[v]<=n&&a[suf[v]]==a[v]-1))
            {
                for(int k=i;k<=j;k++)
                    del(pos[l][k]);
            }
            else
            {
                cout<<"NO\n";
                return;
            }
            j++;
        }
    }
    cout<<"YES\n";
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