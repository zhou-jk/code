//HYSBZ-1047
#include <cstdio>
#include <algorithm>

using std::min;

const int N=1000;
int num[N],q1[N],q2[N],s1[N][N],s2[N][N];

int main()
{
	int a,b,n,l1,r1,l2,r2,ans=2e9;
	scanf("%d%d%d",&a,&b,&n);
	for (int i=0; i<a; i++)
	{
		l1=r1=l2=r2=0;
		for (int j=0; j<n-1; j++)
		{
			scanf("%d",&num[j]);
			while (l1<r1&&num[q1[r1-1]]>=num[j]) r1--;
			while (l2<r2&&num[q2[r2-1]]<=num[j]) r2--;
			q1[r1++]=q2[r2++]=j;
		}
		for (int j=n-1; j<b; j++)
		{
			scanf("%d",&num[j]);
			while (l1<r1&&q1[l1]<=j-n) l1++;
			while (l2<r2&&q2[l2]<=j-n) l2++;
			while (l1<r1&&num[q1[r1-1]]>=num[j]) r1--;
			while (l2<r2&&num[q2[r2-1]]<=num[j]) r2--;
			q1[r1++]=q2[r2++]=j;
			s1[i][j-n+1]=num[q1[l1]]; s2[i][j-n+1]=num[q2[l2]];
		}
	}
	for (int i=0; i<=b-n; i++)
	{
		l1=r1=l2=r2=0;
		for (int j=0; j<n-1; j++)
		{
			while (l1<r1&&s1[q1[r1-1]][i]>=s1[j][i]) r1--;
			while (l2<r2&&s2[q2[r2-1]][i]<=s2[j][i]) r2--;
			q1[r1++]=q2[r2++]=j;
		}
		for (int j=n-1; j<a; j++)
		{
			while (l1<r1&&q1[l1]<=j-n) l1++;
			while (l2<r2&&q2[l2]<=j-n) l2++;
			while (l1<r1&&s1[q1[r1-1]][i]>=s1[j][i]) r1--;
			while (l2<r2&&s2[q2[r2-1]][i]<=s2[j][i]) r2--;
			q1[r1++]=q2[r2++]=j;
			ans=min(ans,s2[q2[l2]][i]-s1[q1[l1]][i]);
		}
	}
	printf("%d",ans);
	return 0;
}