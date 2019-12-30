#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m;
int book[N];
int fa[N],dis[N];
vector<int>X;
struct Node
{
    int f,s;
}a[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    int f=fa[v];
    fa[v]=getf(fa[v]);
    dis[v]+=dis[f];
    return fa[v];
}
bool merge(int u,int v,int w)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        fa[f1]=f2;
        dis[f1]=dis[v]+w-dis[u];
        return true;
    }
    else return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=0;i<=m*2;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a[i].f,&a[i].s);
        if(a[i].f>a[i].s) swap(a[i].f,a[i].s);
        a[i].f--;
        X.push_back(a[i].f),X.push_back(a[i].s);
        string s;
        cin>>s;
        if(s=="odd") book[i]=1;
        else if(s=="even") book[i]=0;
    }
    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    for(int i=1;i<=m;i++)
    {
        a[i].f=lower_bound(X.begin(),X.end(),a[i].f)-X.begin()+1;
        a[i].s=lower_bound(X.begin(),X.end(),a[i].s)-X.begin()+1;
        if(merge(a[i].f,a[i].s,book[i])) ans++;
        else
        {
            if(abs(dis[a[i].f]-dis[a[i].s])%2==book[i]) ans++;
            else break;
        }
    }
    printf("%d",ans);
    return 0;
}