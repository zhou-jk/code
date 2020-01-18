//POJ-1840
#include <cstdio>
#include <algorithm>

using std::sort;
using std::lower_bound;
using std::upper_bound;

const int N=100,S=N*N*N;
int a[5],x[N],s[S];

int main()
{
	int ans=0;
	for (int i=0; i<5; i++) scanf("%d",&a[i]);
	for (int i=-50; i<0; i++) x[i+50]=i*i*i;
	for (int i=1; i<=50; i++) x[i+49]=i*i*i;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			for (int k=0; k<N; k++)
				s[i*N*N+j*N+k]=a[0]*x[i]+a[1]*x[j]+a[2]*x[k];
	sort(s,s+S);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
		{
			int tmp=a[3]*x[i]+a[4]*x[j];
			ans+=upper_bound(s,s+S,tmp)-lower_bound(s,s+S,tmp);
		}
	printf("%d",ans);
	return 0;
}