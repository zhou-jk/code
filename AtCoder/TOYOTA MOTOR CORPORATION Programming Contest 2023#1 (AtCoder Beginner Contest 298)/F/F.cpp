#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int x[N],y[N],v[N];
int bx[N],totx,by[N],toty;
long long sumx[N],sumy[N];
map<pair<int,int>,int>book;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&x[i],&y[i],&v[i]);
    for(int i=1;i<=n;i++)
        bx[++totx]=x[i],by[++toty]=y[i];
    sort(bx+1,bx+totx+1);
    totx=unique(bx+1,bx+totx+1)-bx-1;
    sort(by+1,by+toty+1);
    toty=unique(by+1,by+toty+1)-by-1;
    for(int i=1;i<=n;i++)
        x[i]=lower_bound(bx+1,bx+totx+1,x[i])-bx,y[i]=lower_bound(by+1,by+toty+1,y[i])-by;
    for(int i=1;i<=n;i++)
        sumx[x[i]]+=v[i],sumy[y[i]]+=v[i],book[make_pair(x[i],y[i])]=v[i];
    int px=max_element(sumx+1,sumx+totx+1)-sumx,py=max_element(sumy+1,sumy+toty+1)-sumy;
    long long ans=0;
    for(int i=1;i<=totx;i++)
        ans=max(ans,sumx[i]+sumy[py]-book[make_pair(i,py)]);
    for(int j=1;j<=toty;j++)
        ans=max(ans,sumx[px]+sumy[j]-book[make_pair(px,j)]);
    printf("%lld",ans);
    return 0;
}