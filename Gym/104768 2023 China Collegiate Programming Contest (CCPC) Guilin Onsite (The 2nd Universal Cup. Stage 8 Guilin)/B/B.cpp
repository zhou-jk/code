#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int N=300005;
int n,m;
int a[N],b[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    multiset<int>sm,sb;
    for(int i=1;i<=n-m;i++)
        sm.insert(a[i]);
    for(int i=1;i<=m;i++)
        sb.insert(a[n-m+i]);
    long long tot=0;
    for(int i=1;i<=m;i++)
        if(a[n-m+i]>b[i])
        {
            cout<<-1<<"\n";
            return;
        }
        else tot+=b[i]-a[n-m+i];
    if(tot>n-m)
    {
        cout<<-1<<"\n";
        return;
    }
    int ret=n;
    vector<int>ans;
    while(ret>m&&tot!=ret-m)
    {
        if(sm.empty())
        {
            cout<<-1<<"\n";
            return;
        }
        int v=*sm.begin();
        ans.emplace_back(v);
        sm.erase(sm.begin());
        sm.insert(v+1);
        while(!sm.empty()&&*sb.begin()<*sm.rbegin())
            tot-=*sm.rbegin(),sb.insert(*sm.rbegin()),sm.erase(prev(sm.end()));
        while((int)sb.size()>m)
            tot+=*sb.begin(),sm.insert(*sb.begin()),sb.erase(sb.begin());
        sm.erase(sm.begin());
        ret--;
    }
    if(tot!=ret-m)
    {
        cout<<-1<<"\n";
        return;
    }
    int i=1;
    for(int u:sb)
    {
        if(u>b[i])
        {
            cout<<-1<<"\n";
            return;
        }
        for(int j=u;j<b[i];j++)
            ans.emplace_back(j);
        i++;
    }
    int l=ans.size();
    cout<<l<<"\n";
    for(int v:ans)
        cout<<v<<" ";
    cout<<"\n";
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