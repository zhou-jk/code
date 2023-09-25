#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=5005;
const long long INF=4557430888798830399;
int n;
int t[N],d[N];
int p[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>t[i]>>d[i];
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return d[x]!=d[y]?d[x]<d[y]:x<y;});
    int now=0;
    for(int i=1;i<=n;i++)
    {
        now+=t[id[i]];
        if(now>d[id[i]])
        {
            cout<<"*";
            return 0;
        }
    }
    static bool vis[N];
    for(int u=1;u<=n;u++)
    {
        static int pos[N];
        int cur=0;
        for(int i=1;i<u;i++)
            pos[++cur]=p[i];
        for(int i=1;i<=n;i++)
            if(!vis[id[i]]) pos[++cur]=id[i];
        long long sum=0;
        for(int i=1;i<u;i++)
            sum+=t[pos[i]];
        long long mn=INF;
        int res=n+1;
        for(int i=u;i<=n;i++)
        {
            sum+=t[pos[i]];
            if(mn>=t[pos[i]]&&!vis[pos[i]]) res=min(res,pos[i]);
            if(d[pos[i]]-sum<mn) mn=d[pos[i]]-sum;
        }
        p[u]=res;
        vis[res]=true;
    }
    for(int i=1;i<=n;i++)
        cout<<p[i]<<" ";
    return 0;
}