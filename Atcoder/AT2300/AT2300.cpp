#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=300005,M=100005;
int n,m;
struct Node
{
    int l,r,len;
}a[N];
bool cmp(Node x,Node y)
{
    return x.len<y.len;
}
struct Binary_Indexed_Tree
{
    int tree[M];
    Binary_Indexed_Tree()
    {
        memset(tree,0,sizeof(tree));
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        if(x==0) return;
        for(int i=x;i<=m;i+=lowbit(i))
            tree[i]+=y;
        return;
    }
    void add(int a,int b,int val)
    {
        if(a>b) return;
        add(a,val);
        add(b+1,-val);
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=tree[i];
        return res;
    }
}T;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,l,r;i<=n;++i)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].len=a[i].r-a[i].l+1;
    }
    sort(a+1,a+n+1,cmp);
    int j=1;
    for(int i=1;i<=m;i++)
    {
        while(j<=n&&a[j].len<i)
        {
            T.add(a[j].l,a[j].r,1);
            j++;
        }
        int ans=n-j+1;
        for(int k=i;k<=m;k+=i)
            ans+=T.getsum(k);
        printf("%d\n",ans);
    }
    return 0;
}
