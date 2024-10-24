#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
#define RI register int
#define CI const int&
using namespace std;
const int N=500005,INF=1e18;
struct ifo
{
    int l,r,v;
    friend inline bool operator < (const ifo& A,const ifo& B)
    {
        return A.v>B.v;
    }
}O[N]; int t,n,m,tl,tr,a[N],fa[N],mxp[N];
inline int getfa(CI x)
{
    return fa[x]!=x?fa[x]=getfa(fa[x]):x;
}
class Segment_Tree
{
    private:
        int mn[N<<2];
    public:
        #define TN CI now=1,CI l=tl,CI r=tr
        #define LS now<<1,l,mid
        #define RS now<<1|1,mid+1,r
        inline void build(TN)
        {
            if (l==r) return (void)(mn[now]=INF);
            int mid=(l+r)/2; build(LS); build(RS);
        }
        inline int query(CI beg,CI end,TN)
        {
        	if (beg>end) return INF;
            if (beg<=l&&r<=end) return mn[now]; int mid=(l+r)/2,ret=INF;
            if (beg<=mid) ret=min(ret,query(beg,end,LS));
            if (end>mid) ret=min(ret,query(beg,end,RS));
            return ret;
        }
        inline void update(CI pos,CI mv,TN)
        {
            if (l==r) return (void)(mn[now]=mv); int mid=(l+r)/2;
            if (pos<=mid) update(pos,mv,LS); else update(pos,mv,RS);
            mn[now]=min(mn[now<<1],mn[now<<1|1]);
        }
        #undef TN
        #undef LS
        #undef RS
}SEG;
inline int solve(CI l,CI r,CI v)
{
    vector <int> vec;
    for (RI i=l;i<=r;++i)
    {
        int x=getfa(O[i].l);
        while (x<=O[i].r)
        {
            vec.push_back(x);
            cerr<<"find"<<x<<"\n";
            fa[x]=x+1; x=getfa(x);
        }
    }
    sort(vec.begin(),vec.end());
    for (RI i=0;i<vec.size();++i) mxp[i]=-1;
    for (RI i=l;i<=r;++i)
    {
        int L=lower_bound(vec.begin(),vec.end(),O[i].l)-vec.begin();
        int R=upper_bound(vec.begin(),vec.end(),O[i].r)-vec.begin()-1;
        cerr<<"find"<<L<<" "<<R<<"\n";
        if (L>R) return -1; else mxp[R]=max(mxp[R],L);
    }
    tl=0; tr=vec.size(); SEG.build(); SEG.update(0,0);
    int lst=-1;
    for (RI i=0;i<vec.size();++i)
    {
        if (i-1>=0) lst=max(lst,mxp[i-1]);
        int tmp=SEG.query(lst+1,i)+abs(a[vec[i]]-v);
        SEG.update(i+1,tmp);
        if (a[vec[i]]<=v) lst=i;
    }
    lst=max(lst,mxp[vec.size()-1]);
    return SEG.query(lst+1,vec.size());
}
signed main()
{
    //freopen("F.in","r",stdin);
    for (scanf("%lld",&t);t;--t)
    {
        scanf("%lld%lld",&n,&m);
        for (RI i=1;i<=n;++i) scanf("%lld",&a[i]);
        for (RI i=1;i<=n+1;++i) fa[i]=i;
        for (RI i=1;i<=m;++i) scanf("%lld%lld%lld",&O[i].l,&O[i].r,&O[i].v);
        sort(O+1,O+m+1); bool flag=1; int ans=0;
        for (RI i=1;i<=m;)
        {
            int j=i;
            while (j+1<=m&&O[j+1].v==O[i].v) ++j;
            int tmp=solve(i,j,O[i].v);
            if (tmp==-1) { flag=0; break; }
            ans+=tmp; i=j+1;
        }
        if (!flag) puts("-1"); else printf("%lld\n",ans);
    }
    return 0;
}
