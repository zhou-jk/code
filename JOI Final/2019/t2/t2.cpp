#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
struct Paint
{
    int s,v;
}a[N];
int c[N];
bool check(int x)
{
    multiset<int>S;
    int pre=0;
    for(int i=m-x+1,j=0;i<=m;i++)
    {
        while(j+1<=n&&a[j+1].s<=c[i]) S.insert(a[j+1].v),j++;
        multiset<int>::iterator it=S.lower_bound(pre);
        if(it==S.end()) return false;
        pre=*it;
        S.erase(it);
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].s,&a[i].v);
    sort(a+1,a+n+1,[=](const Paint &x,const Paint &y){return x.s<y.s;});
    for(int i=1;i<=m;i++)
        scanf("%d",&c[i]);
    sort(c+1,c+m+1);
    int l=1,r=m,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}