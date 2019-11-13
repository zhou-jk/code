#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn=100010;
const int N=50000;
int n;
struct Node
{
    int sk,sb;
}tree[N<<2];
char str[10];
void update(int i,int l,int r,double k,double b)
{
    if(tree[i].sk*l+tree[i].sb<k*l+b&&tree[i].sk*r+tree[i].sb<k*r+b)
    {
        tree[i].sk=k,tree[i].sb=b;
        return;
    }
    if(tree[i].sk*l+tree[i].sb>=k*l+b&&tree[i].sk*r+tree[i].sb>=k*r+b) return;
    int mid=(l+r)/2;
    update(i*2,l,mid,k,b);
    update(i*2+1,mid+1,r,k,b);
    return;
}
double query(int i,int l,int r,int k)
{
    int mid=(l+r)/2;
    double res=k*tree[i].sk+tree[i].sb;
    if(l==r) return res;
    if(k<=mid) res=max(res,query(i*2,l,mid,k));
    else res=max(res,query(i*2+1,mid+1,r,k));
    return res;
}
int main()
{
    scanf("%d",&n);
    int c;
    double k,b;
    while(n--)
    {
        scanf("%s",str);
        if(str[0]=='Q') scanf("%d",&c),printf("%d\n",int(floor(query(1,1,N,c)/100)));
        else  scanf("%lf%lf",&k,&b),update(1,1,N,b,k-b);
    }
    return 0;
}