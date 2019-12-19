#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100001;
struct Line
{
    long long x,y;
};
bool cmp(Line a,Line b)
{
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
double slope(Line a,Line b)
{
    return (double)(b.y-a.y)/(b.x-a.x);
}
int n,m;
int a[N],sum[N];
struct Node
{
    int l,r;
    vector<Line>A;
}tree[N<<2];
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    vector<Line>tmp;
    tmp.clear();
    for(int i=l;i<=r;i++)
        tmp.push_back((Line){a[i],-sum[i-1]+(i-1)*a[i]});
    sort(tmp.begin(),tmp.end(),cmp);
    for(auto u:tmp)
    {
        if(!tree[i].A.size()) tree[i].A.push_back(u);
        else if(u.x!=tree[i].A[tree[i].A.size()-1].x)
        {
            while(tree[i].A.size()>=2)
            {
                int m=tree[i].A.size();
                if(slope(tree[i].A[m-2],tree[i].A[m-1])>=slope(tree[i].A[m-1],u)) tree[i].A.pop_back();
                else break;
            }
            tree[i].A.push_back(u);
        }
    }
    if(l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    return;
}
long long getval(Line a,int k)
{
    return a.y-k*a.x;
}
long long getkth(const vector<Line>&v,int k)
{
    int l=0,r=v.size()-1,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(slope(v[mid],v[mid+1])>=k) ans=mid,r=mid-1;
        else l=mid+1;
    }
    return getval(v[ans],k);
}
long long query(int i,int l,int r,int k)
{
    if(l<=tree[i].l&&tree[i].r<=r) return getkth(tree[i].A,k);
    int mid=(tree[i].l+tree[i].r)/2;
    long long res=1e18;
    if(l<=tree[i*2].r) res=min(res,query(i*2,l,r,k));
    if(r>=tree[i*2+1].l) res=min(res,query(i*2+1,l,r,k));
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",query(1,y-x+1,y,y-x)+sum[y]);
    }
    return 0;
}