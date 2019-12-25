#include<iostream>
#include<cstdio>
using namespace std;
const int N=100000;
int n;
double K[N+1],B[N+1];
int cnt;
double f(int i,int x)
{
    return K[i]*x+B[i];
}
int lazy[N<<2|1];
int query(int i,int l,int r,int u)
{
    if(l==r) return lazy[i];
    int mid=(l+r)/2,pos;
    if(u<=mid) pos=query(i*2,l,mid,u);
    else pos=query(i*2+1,mid+1,r,u);
    if(f(lazy[i],u)<f(pos,u)) return pos;
    else return lazy[i];
}
void modify(int i,int l,int r,int pos)
{
    if(!lazy[i])
    {
        lazy[i]=pos;
        return;
    }
    if(l==r)
    {
        if(f(pos,l)>f(lazy[i],l)) lazy[i]=pos;
        return;
    }
    int mid=(l+r)/2;
    if(K[pos]>K[lazy[i]])
    {
        if(f(pos,mid)>f(lazy[i],mid)) modify(i*2,l,mid,lazy[i]),lazy[i]=pos;
        else modify(i*2+1,mid+1,r,pos);
    }
    if(K[pos]<K[lazy[i]])
    {
        if(f(pos,mid)>f(lazy[i],mid)) modify(i*2+1,mid+1,r,lazy[i]),lazy[i]=pos;
        else modify(i*2,l,mid,pos);
    }
    if(K[pos]==K[lazy[i]])
    {
        if(B[pos]>B[lazy[i]])
        {
            modify(i*2,l,mid,pos);
            modify(i*2+1,mid+1,r,pos);
            lazy[i]=pos;
        }
    }
    return;
}
void update(int i,int l,int r,int L,int R,int u)
{
    if(L<=l&&r<=R)
    {
        modify(i,l,r,u);
        return;
    }
    int mid=(l+r)/2;
    if(L<=mid) update(i*2,l,mid,L,R,u);
    if(R>mid) update(i*2+1,mid+1,r,L,R,u);
    return;
}
int main()
{
    scanf("%d",&n);
    int lastans=0;
    for(int i=1;i<=n;i++)
    {
        int op;
        scanf("%d",&op);
        if(op)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            cnt++;
            x1=(x1+lastans-1)%39989+1,y1=(y1+lastans-1)%1000000000+1;
            x2=(x2+lastans-1)%39989+1,y2=(y2+lastans-1)%1000000000+1;
            if(x1>x2) swap(x1,x2),swap(y1,y2);
            if(x1==x2) K[cnt]=0,B[cnt]=max(y1,y2);
            else K[cnt]=(double)(y2-y1)/(x2-x1),B[cnt]=y1-K[cnt]*x1;
            update(1,1,N,x1,x2,cnt);
        }
        else
        {
            int x;
            scanf("%d",&x);
            x=(x+lastans-1)%39989+1;
            lastans=query(1,1,N,x);
            printf("%d\n",lastans);
        }
    }
    return 0;
}