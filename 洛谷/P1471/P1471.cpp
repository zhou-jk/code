#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n,m;
double a[N];
struct Node
{
    int l,r;
    double avg,cha,lazy;
}tree[N<<2];
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].avg=a[l],tree[i].cha=
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lf",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int op,x,y,k;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d",&x,&y,&k);
            
        }
    }
}