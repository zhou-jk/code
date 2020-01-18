#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=16384;
int n,m,c,p;
bool book[10001];
int s[10001],tot;
int a[50001];
int prime[30],num[50001],M;
long long pw[40][N+1],Pw[40][N+1];
struct Node
{
    int l,r;
    long long lazy,sum;
}tree[200001];
void push_up(int i)
{
    tree[i].lazy=tree[i*2].lazy+tree[i*2+1].lazy;
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%p;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].sum=a[l],tree[i].lazy=1;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
long long pow(int k,int mod)
{
    if(k==0) return 1;
    else return Pw[mod][k&(N-1)]*pw[mod][k>>14]%prime[mod];
}
int calc(int x,int p)
{
    int res=x%prime[p];
    bool flag=x>=prime[p];
    for(int i=p;i>0;i--)
    {
        if(flag) res+=prime[i];
        res=pow(res,i-1);
        if(!flag&&res>=log(prime[i-1]/log(c))) flag=true;
    }
    return res;
}
void add(int i)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum=calc(a[tree[i].l],++num[tree[i].l]);
        if(num[tree[i].l]==M) tree[i].lazy=0;
    }
    else
    {
        if(tree[i*2].lazy) add(i*2);
        if(tree[i*2+1].lazy) add(i*2+1);
        push_up(i);
    }
    return;
}
void update(int i,int l,int r)
{
    if(tree[i].lazy==0) return;
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        add(i);
        return;
    }
    if(l<=tree[i*2].r) update(i*2,l,r);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r);
    push_up(i);
    return;
}
long long query(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    long long res=0;
    if(l<=tree[i*2].r) res=(res+query(i*2,l,r))%p;
    if(r>=tree[i*2+1].l) res=(res+query(i*2+1,l,r))%p;
    return res;
}
int getprime(int sum)
{
    int res=sum;
    for(int i=1;i<=tot&&s[i]<=sum;i++)
        if(sum%s[i]==0)
        {
            res=res/s[i]*(s[i]-1);
            while(sum%s[i]==0)
                sum/=s[i];
        }
    if(sum>1) res=res/sum*(sum-1);
    return res;
}
void init()
{
    for(int i=2;i<=sqrt(p);i++)
    {
        if(!book[i]) s[++tot]=i;
        for(int j=1;s[j]*i<=sqrt(p);j++)
        {
            book[s[j]*i]=true;
            if(i%s[j]==0) break;
        }
    }
    prime[0]=p;
    while(prime[M]>1)
        M++,prime[M]=getprime(prime[M-1]);
    prime[++M]=1;
    for(int i=0;i<M-1;i++)
    { 
        Pw[i][0]=pw[i][0]=1;
        for(int j=1;j<=N;j++)
            Pw[i][j]=Pw[i][j-1]*c%prime[i];
        for(int j=1;j<=N;j++)
            pw[i][j]=pw[i][j-1]*Pw[i][N]%prime[i];
    }
    return;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&p,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    init();
    for(int i=1;i<=m;i++)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==0) update(1,l,r);
        else if(op==1) printf("%lld\n",query(1,l,r));
    }
    return 0;
}