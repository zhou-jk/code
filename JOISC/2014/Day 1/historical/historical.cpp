#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,q;
int a[N];
int b[N],m;
int bel[N];
int SIZE;
struct Block
{
    int l,r;
}block[N];
void init()
{
    SIZE=sqrt(n);
    for(int i=1;i<=n;i++)
        bel[i]=(i-1)/SIZE+1;
    for(int i=1;i<=(n-1)/SIZE+1;i++)
        block[i].l=(i-1)*SIZE+1,block[i].r=min(i*SIZE,n);
    return;
}
struct Query
{
    int l,r,id;
}query[N];
int l,r;
long long res;
long long ans[N];
int cnt[N];
void add(int i)
{
    cnt[a[i]]++;
    res=max(res,(long long)b[a[i]]*cnt[a[i]]);
    return;
}
void del(int i)
{
    cnt[a[i]]--;
    return;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        b[++m]=a[i];
    sort(b+1,b+m+1);
    m=unique(b+1,b+m+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    init();
    for(int i=1;i<=q;i++)
        scanf("%d%d",&query[i].l,&query[i].r),query[i].id=i;
    sort(query+1,query+q+1,[=](const Query &a,const Query &b){return bel[a.l]!=bel[b.l]?bel[a.l]<bel[b.l]:a.r<b.r;});
    int l=1,r=0;
    int last=0;
    for(int t=1;t<=q;t++)
    {
        if(bel[query[t].l]==bel[query[t].r])
        {
            static int c[N];
            long long now=0;
            for(int i=query[t].l;i<=query[t].r;i++)
                c[a[i]]++;
            for(int i=query[t].l;i<=query[t].r;i++)
                now=max(now,(long long)b[a[i]]*c[a[i]]);
            for(int i=query[t].l;i<=query[t].r;i++)
                c[a[i]]--;
            ans[query[t].id]=now;
            continue;
        }
        if(bel[query[t].l]!=last)
        {
            while(r>block[bel[query[t].l]].r) del(r),r--;
            while(l<=block[bel[query[t].l]].r) del(l),l++;
            res=0;
            last=bel[query[t].l];
        }
        while(r<query[t].r) r++,add(r);
        long long tmp=res;
        int L=l;
        while(L>query[t].l) L--,add(L);
        ans[query[t].id]=res;
        while(L<l) del(L),L++;
        res=tmp;
    }
    for(int i=1;i<=q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}