
#include <cstdio>

const int N=200000;
int num[N],q[N],r;

int query(int k)
{
	int ll=0,rr=r-1,mid;
	while (ll<rr)
	{
		mid=(ll+rr)>>1;
		if (q[mid]>k) rr=mid;
		else ll=mid+1;
	}
	return q[ll];
}

int main()
{
	char a;
	char e[2];
	int n,d,b,t=0,cnt=0;
	scanf("%d %d",&n,&d);
	for (int i=0; i<n; i++)
	{
		gets(e);
		scanf("%c%d",&a,&b);
		if (a=='Q')
		{
			printf("%d\n",t=num[query(cnt-1-b)]);
		}
		else
		{
			num[cnt]=(b+t)%d;
			while (0<r&&num[cnt]>=num[q[r-1]]) r--;
			q[r++]=cnt++;
		}
	}
	return 0;
}