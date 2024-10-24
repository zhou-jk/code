#include<bits/stdc++.h>
using namespace std;
constexpr int N=300005;
struct Node
{
    int op,val,x,y,id;
}a[N];
struct Bianry_Array
{
    int c[N];
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<N;i+=lowbit(i))
            c[i]+=y;
        return;
    }
    int query(int x)
    {
        x=min(x,N-1);
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=c[i];
        return res;
    }
} BA;
int ans[N];
void cdq(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    vector<Node>b;
    for(int i=l;i<=mid;i++)
        if(a[i].op) b.emplace_back(a[i]);
    for(int i=mid+1;i<=r;i++)
        if(!a[i].op) b.emplace_back(a[i]);
    sort(b.begin(),b.end(),[&](const Node &a,const Node &b){return a.x<b.x||(a.x==b.x&&abs(a.op)>abs(b.op));});
    for(int i=0;i<(int)b.size();i++)
        if(b[i].op) BA.add(b[i].y, b[i].op);
        else
        {
            if(b[i].id>0) ans[b[i].id]+=BA.query(b[i].y);
            else ans[-b[i].id]-=BA.query(b[i].y);
        }
    for(int i=0;i<(int)b.size();i++)
        if(b[i].op) BA.add(b[i].y,-b[i].op);
    return;
}
int tot;
map<int,vector<pair<int,int>>>mp;
void init(int n)
{
    for(int i=4;(long long)i*(i-1)/2<=n;i++)
    {
        long long val=i;
        for(int j=2;j<=i/2;j++)
        {
            val*=(i-j+1);
            val/=j;
            if(val>n) break;
            mp[val].emplace_back(i,j);
        }
    }
    for(auto &[val,pos]:mp)
    {
        int m=pos.size();
        for(int s=1;s<(1<<m);s++)
        {
            int mxx=0,mxy=0,f=-1;
            for(int i=0;i<m;i++)
                if((s>>i)&1)
                {
                    mxx=max(mxx,pos[i].first);
                    mxy=max(mxy,pos[i].second);
                    f=-f;
                }
            a[++tot]={f,val,mxx,mxy,0};
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int q;
    cin>>q;
    init(1e9);
    for(int t=1;t<=q;t++)
    {
        int l,r,n,m;
        cin>>l>>r>>n>>m;
        if(n+1<=r)
        {
            a[++tot]={0,max(l,n+1)-1,n,m,-t};
            a[++tot]={0,r,n,m,t};
        }
        ans[t]=max(0,min(n,r)-l+1);
    }
    sort(a+1,a+tot+1,[&](const Node &a,const Node &b){return a.val<b.val||(a.val==b.val&&abs(a.op)>abs(b.op));});
    cdq(1,tot);
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<"\n";
    return 0;
}