#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<numeric>
using namespace std;
const int N=100005;
int n;
int s[N];
map<pair<vector<int>,int>,int>vis;
int tot;
int nxt[N*10];
pair<vector<int>,int> val[N*10];
int res[N*10],op[N*10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=2;i<=n;i++)
        if(s[i-1]-s[i]>1)
        {
            cout<<-1;
            return 0;
        }
    queue<pair<vector<int>,int>>q;
    q.emplace(vector<int>({s[n]}),0);
    vis[{vector<int>({s[n]}),0}]=++tot;
    val[tot]={vector<int>({s[n]}),0};
    int cur=0;
    while(!q.empty())
    {
        auto [a,num]=q.front();
        q.pop();
        int t=n-((int)a.size()+num)+1;
        int id=vis[{a,num}];
        if(t==1)
        {
            cur=id;
            break;
        }
        if(s[t-1]==s[t]+1)
        {
            if(vis.count({a,num+1})) continue;
            q.emplace(a,num+1);
            vis[{a,num+1}]=++tot;
            nxt[tot]=id;
            val[tot]={a,num+1};
            continue;
        }
        for(int i=0;i<(int)a.size();i++)
            for(int x=2;x*x<=a[i];x++)
                if(a[i]%x==0)
                {
                    int y=a[i]/x;
                    if(s[t]-s[t-1]==x*y-x-y)
                    {
                        vector<int>b;
                        for(int j=0;j<(int)a.size();j++)
                            if(j!=i) b.emplace_back(a[j]);
                            else b.emplace_back(x),b.emplace_back(y);
                        if(vis.count({b,num})) continue;
                        q.emplace(b,num);
                        vis[{b,num}]=++tot;
                        nxt[tot]=id;
                        val[tot]={b,num};
                    }
                }
    }
    if(cur==0)
    {
        cout<<-1;
        return 0;
    }
    auto [a,num]=val[cur];
    int c=0;
    for(int u:a)
        res[++c]=u;
    for(int i=1;i<=num;i++)
        res[++c]=1;
    for(int i=1;i<=n;i++)
        cout<<res[i]<<" ";
    cout<<"\n";
    vector<int>id(a.size());
    iota(id.begin(),id.end(),1);
    int p=id.size();
    for(int i=1;i<n;i++)
    {
        auto [b,nnum]=val[nxt[cur]];
        if(num==nnum+1)
        {
            op[i]=p;
            p++;
        }
        else
        {
            for(int j=0;j<(int)b.size();j++)
                if(b[j]!=a[j])
                {
                    op[i]=id[j];
                    id.erase(id.begin()+j);
                    break;
                }
        }
        cur=nxt[cur];
        a=b,num=nnum;
    }
    for(int i=1;i<n;i++)
        cout<<op[i]<<"\n";
    return 0;
}