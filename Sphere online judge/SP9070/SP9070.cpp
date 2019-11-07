#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int a[500001],k[500001];
int q[500001],head,tail;
double p[500001];
double Sqrt[500001];
double get_f(int i,int j)
{
    return a[j]+Sqrt[i-j];
}
int get_k(int x,int y)
{
    int l=y,r=k[x]?k[x]:n,mid,ans=r+1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(get_f(mid,x)<=get_f(mid,y)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}
void get_ans()
{
    int head=1,tail=0;
    for(int i=1;i<=n;i++)
    {
        while(head<tail&&k[head]<=i) head++;
        while(head<tail&&get_f(k[tail-1],q[tail])<get_f(k[tail-1],i)) tail--;
        k[tail]=get_k(q[tail],i);
        q[++tail]=i;
        p[i]=max(p[i],get_f(i,q[head]));
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        Sqrt[i]=sqrt(i);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    get_ans();
    for(int i=1,j=n;i<j;i++,j--)
        swap(a[i],a[j]),swap(p[i],p[j]);
    memset(k,0,sizeof(k));
    get_ans();
    for(int i=n;i>0;i--)
        printf("%d\n",max((int)ceil(p[i])-a[i],0));
    return 0;
}