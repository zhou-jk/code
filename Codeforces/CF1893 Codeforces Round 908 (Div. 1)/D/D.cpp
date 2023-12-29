#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=200005;
int n,m;
int c[N];
int a[N],d[N],s[N];
vector<int>res[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>s[i];
    for(int i=1;i<=m;i++)
        cin>>d[i];
    for(int i=1;i<=n;i++)
        c[i]=0;
    for(int i=1;i<=n;i++)
        c[a[i]]++;
    priority_queue<pair<int,int>>q;
    for(int i=1;i<=n;i++)
        if(c[i]) q.emplace(c[i],i);
    for(int i=1;i<=m;i++)
    {
        vector<pair<int,int>>now(d[i]);
        res[i].resize(s[i]);
        int k=0;
        for(int t=1;t<=s[i]/d[i];t++)
        {
            for(int j=0;j<d[i];j++)
            {
                if(q.empty())
                {
                    cout<<-1<<"\n";
                    return;
                }
                now[j]=q.top();
                q.pop();
                res[i][k++]=now[j].second;
                now[j].first--;
            }
            for(int j=0;j<d[i];j++)
                if(now[j].first>0) q.emplace(now[j]);
        }
        for(int j=0;j<s[i]%d[i];j++)
        {
            if(q.empty())
            {
                cout<<-1<<"\n";
                return;
            }
            now[j]=q.top();
            q.pop();
            res[i][k++]=now[j].second;
            now[j].first--;
        }
        for(int j=0;j<s[i]%d[i];j++)
            if(now[j].first>0) q.emplace(now[j]);
    }
    for(int i=1;i<=m;i++)
    {
        for(int col:res[i])
            cout<<col<<" ";
        cout<<"\n";
    }
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