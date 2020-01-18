#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100001;
const int MOD=99999997; 
struct Node
{
    int val,id;
}a[N],b[N];
int n;
int d[N];
bool cmp(Node a,Node b)
{
    return a.val<=b.val;
}
long long tree[N];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]=(tree[i]+y)%MOD;
    return;
}
int query(int x)
{
    long long ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        ans=(ans+tree[i])%MOD;
    return ans;
}
int main() 
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].val);
        a[i].id=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i].val);
        b[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++)
        d[a[i].id]=b[i].id;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        add(d[i],1);
        ans=(ans+i-query(d[i]))%MOD;
    } 
    printf("%lld",ans);
    return  0;
}