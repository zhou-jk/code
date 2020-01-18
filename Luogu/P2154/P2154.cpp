#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long MOD=2147483648;
int n,m,w;
int K,H[200001];
long long c[100001][11];
long long ans;
struct Node
{
    int x,y;
}a[100001];
bool cmp(Node a,Node b)
{
	if(a.y!=b.y) return a.y<b.y;
    else return a.x<b.x;
}
long long tree[200001];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int y)
{
    for(int i=x;i<=2*w;i+=lowbit(i))
        tree[i]=(tree[i]+y)%MOD;
    return;
}
long long query(int x)
{
    long long res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res=(res+tree[i])%MOD;
    return res;
}
int h[200001],l[200001];
int num[200001];
int main()
{
	scanf("%d%d%d",&m,&n,&w);
	for(int i=1;i<=w;i++)
	{
	    scanf("%d%d",&a[i].x,&a[i].y);
	    H[2*i-1]=a[i].x;
	    H[2*i]=a[i].y;
    }
    scanf("%d",&K);
    c[0][0]=1;
	for(int i=1;i<=w;i++)
	{
        c[i][0]=1;
	    for(int j=1;j<=min(K,i);j++)
	        c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	}
    sort(H+1,H+2*w+1);
    for(int i=1;i<=w;i++)
    {
        h[lower_bound(H+1,H+2*w+1,a[i].y)-H]++;
	    l[lower_bound(H+1,H+2*w+1,a[i].x)-H]++;
    }
    sort(a+1,a+w+1,cmp);
    int cnt=0;
    for(int i=1;i<=w;i++)
    {
   	    if(i>1&&a[i].y==a[i-1].y)
   	    {
   	  	    cnt++;
   	        long long t1=query(lower_bound(H+1,H+2*w+1,a[i].x)-H-1)-query(lower_bound(H+1,H+2*w+1,a[i-1].x)-H);
			long long t2=c[cnt][K]*c[h[lower_bound(H+1,H+2*w+1,a[i].y)-H]-cnt][K];
			ans=(ans+t1*t2%MOD)%MOD;
 	    }
 	    else cnt=0;
   	    int d=lower_bound(H+1,H+2*w+1,a[i].x)-H;num[d]++;
   	    int val=(c[num[d]][K]*c[l[d]-num[d]][K]-c[num[d]-1][K]*c[l[d]-num[d]+1][K])%MOD;
   	    add(d,val);
    }
    printf("%lld",(ans+MOD)%MOD);
	return 0;
}