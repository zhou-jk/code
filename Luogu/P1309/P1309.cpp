#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,r,q,win,lose;
struct Node
{
    int val,data,id;
}a[200001],w[100001],l[100001];
bool cmp(Node a,Node b)
{
    if(a.val!=b.val) return a.val>b.val;
    return a.id<b.id;
}
int main()
{
    scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=2*n;i++)
		a[i].id=i;
    for(int i=1;i<=2*n;i++)
        scanf("%d",&a[i].val);
    for(int i=1;i<=n*2;i++)
        scanf("%d",&a[i].data);
    sort(a+1,a+2*n+1,cmp);
    for(int i=1;i<=r;i++)
	{
        win=0,lose=0;
        for(int j=1;j<=2*n;j+=2)
            if(a[j].data>a[j+1].data) win++,lose++,w[win]=a[j],w[win].val++,l[lose]=a[j+1];
            else win++,lose++,w[win]=a[j+1],w[win].val++,l[lose]=a[j];
        merge(w+1,w+1+win,l+1,l+1+lose,a+1,cmp);
    }
    printf("%d",a[q].id);
    return 0;
}