#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int INF=1000000000;
const int N=500001;
int n,k;
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int h[N],high[N];
struct Node
{
    int id,high;
    bool operator < (const Node &rhs)const
    {
        return high<rhs.high;
    }
}cave[N];
void dfs1(int u,int father,int now)
{
    high[u]=now;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs1(v,u,min(now,h[v]));
    }
    return;
}
vector<int>tmp;
void dfs2(int u,int father,int now)
{
    tmp.push_back(now);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        int newh=min(now,h[v]) ;
        if(newh>high[v]) dfs2(v,u,newh);
    }
    return;
}
multiset<int>st;
vector<int>st_tmp;
bool judge()
{
    if(tmp.size()<st.size()) return false;
    st_tmp.clear();
    for(auto u:tmp)
    {
        if(st.empty()) break;
        multiset<int>::iterator it=st.upper_bound(u);
        if(it!=st.begin())
        {
            it--;
            st_tmp.push_back(*it);
            st.erase(it);
        }
    }
    bool res=st.empty();
    for(auto u:st_tmp)
        st.insert(u);
    return res;
}
int LIM;
bool dfs(int u,int father,int add)
{
    if(h[u]<=LIM)
    {
        int newh=min(high[father],h[u]+add);
        if(newh>high[u])
        {
            tmp.clear();
            dfs2(u,father,newh);
            if(judge()) return true;
        }
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        if(dfs(v,u,add)) return true;
    }
    return false;
}
bool check(int x)
{
    return dfs(1,0,x);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs1(1,0,h[1]);
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        st.insert(x);
    }
    for(int i=k+1;i<=n;i++)
        st.insert(0);
    for(int i=1;i<=n;i++)
        cave[i]=(Node){i,high[i]};
    sort(cave+1,cave+n+1);
    LIM=-1;
    for(int i=1;i<=n;i++)
    {
        multiset<int>::iterator it=st.upper_bound(cave[i].high);
        if(it!=st.begin()) st.erase(--it);
        else if(LIM==-1) LIM=cave[i].high;
    }
    if(st.empty())
    {
        printf("0\n");
        return 0;
    }
    high[0]=INF;
    int l=0,r=INF,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}