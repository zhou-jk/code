#define N 5000

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int x[N],y[N];
long long d[N];
double ans;
bool v[N];

int main() {
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		d[i]=10000000000000;
    }
	d[0]=0;
	for (int i=0;i<n;i++) {
		int k=-1;
		for (int j=0;j<n;j++)
			if (!v[j]&&(k<0||d[j]<d[k])) k=j;
		v[k]=true;
		ans+=sqrt(d[k]);
		for (int j=1;j<n;j++) 
			if (!v[j]) {
				long long t1=x[k]-x[j],t2=y[k]-y[j];
				d[j]=min(d[j],t1*t1+t2*t2);
			}
	}
	printf("%.2lf",ans);
	return 0;
}
