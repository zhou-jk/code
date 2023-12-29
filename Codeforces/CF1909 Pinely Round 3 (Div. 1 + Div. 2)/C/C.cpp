#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int l[N],r[N],c[N];
pair<int,int> b[N*2];
int tot;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>l[i];
    for(int i=1;i<=n;i++)
        cin>>r[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    sort(l+1,l+n+1);
    sort(r+1,r+n+1);
    sort(c+1,c+n+1);
    tot=0;
    for(int i=1;i<=n;i++)
        b[++tot]={l[i],1},b[++tot]={r[i],-1};
    sort(b+1,b+tot+1);
    vector<int>len;
    stack<int>s;
    for(int i=tot;i>=1;i--)
        if(b[i].second==1)
        {
            len.emplace_back(s.top()-b[i].first);
            s.pop();
        }
        else s.emplace(b[i].first);
    sort(len.begin(),len.end(),greater<int>());
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=(long long)len[i-1]*c[i];
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