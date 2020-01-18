#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
const long long INF=2000000000000000000;
int n;
long long k;
int a[N];
int pos[N];
int dp[N],g[N];
long long f[N],h[N];
struct Binary_Indexed_Tree
{
    pair<int,long long>tree[N];
    void clear()
    {
        memset(tree,0,sizeof(tree));
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,pair<int,long long> y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            if(y.first>tree[i].first) tree[i].first=y.first,tree[i].second=y.second;
            else if(y.first==tree[i].first) tree[i].second=min(tree[i].second+y.second,INF);
        return;
    }
    pair<int,long long> query(int x)
    {
        int V=0;
        long long C=1;
        for(int i=x;i>0;i-=lowbit(i))
            if(tree[i].first>V) V=tree[i].first,C=tree[i].second;
            else if(tree[i].first==V) C=min(C+tree[i].second,INF);
        return make_pair(V,C);
    }
}T;
vector<int>block[N];
bool book[N];
int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    T.clear();
    T.add(n-a[n]+1,make_pair(1,1));
    dp[n]=f[n]=1;
    for(int i=n-1;i>0;i--)
    {
        pair<int,long long> res=T.query(n-a[i]+1);
        dp[i]=res.first+1,f[i]=res.second;
        T.add(n-a[i]+1,make_pair(dp[i],f[i]));
    }
    int ans=*max_element(dp+1,dp+n+1);
    T.clear();
    T.add(a[1],make_pair(1,1));
    g[1]=h[1]=1;
    for(int i=2;i<=n;i++)
    {
        pair<int,long long> res=T.query(a[i]);
        g[i]=res.first+1,h[i]=res.second;
        T.add(a[i],make_pair(g[i],h[i]));
    }
    printf("%d\n",n-ans);
    for(int i=1;i<=n;i++)
        if(dp[i]+g[i]-1==ans) block[g[i]].push_back(a[i]);
    for(int i=1;i<=ans;i++)
        sort(block[i].begin(),block[i].end(),greater<int>());
    int lst=-1,pre=-1;
    for(int i=1;i<=ans;i++)
        for(auto x:block[i])
        {
            if(x<lst||pos[x]<pre)continue;
            if(k<=f[pos[x]])
            {
                lst=x,pre=pos[x];
                book[x]=true;
                break;
            }
            k-=f[pos[x]];
        }
    for(int i=1;i<=n;i++)
        if(!book[i]) printf("%d\n",i);
    return 0;
}