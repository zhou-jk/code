#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int n,m;
struct Binary_Indexed_Tree
{
    int tree[N];
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
        for(int i=x;i<=n;i+=lowbit(i))
            tree[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=tree[i];
        return res;
    }
}T1,T2;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1) T1.add(l,1),T2.add(r,1);
        else printf("%d\n",T1.getsum(r)-T2.getsum(l-1));
    }
    return 0;
}