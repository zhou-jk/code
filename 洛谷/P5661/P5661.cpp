#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
// #define j i
int n;
int pre[N],nxt[N],head,tot;
long long ans;
void del(int i)
{
    if(i==head) head=nxt[i];
    pre[nxt[i]]=pre[i];
    nxt[pre[i]]=nxt[i];
    return;
}
struct Node
{
    int val,time;
}a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        pre[i]=i-1,nxt[i]=i+1;
    head=1;
    for(int i=1;i<=n;i++)
    {
        int op,price,t;
        scanf("%d%d%d",&op,&price,&t);
        if(op==0) tot++,a[tot].val=price,a[tot].time=t,ans+=price;
        else if(op==1)
        {
            for(int j=head;j<=tot;j=nxt[j])
                if(t-a[j].time>45) del(j);
                else break;
            bool flag=false;
            for(int j=head;j<=tot;j=nxt[j])
                if(price<=a[j].val)
                {
                    flag=true;
                    del(j);
                    break;
                }
            if(!flag) ans+=price;
        }
    }
    printf("%lld",ans);
    return 0;
}