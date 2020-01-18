//PrayerOJ 2142(TLE)(N=100000)&VJ LA 2184(N=100)
#define N 100

#include <cstdio>
#include <algorithm>

using namespace std;

double x1[N],y1[N],x2[N],y2[N],x[N<<1],y[N<<1];
int t;

int main() {
	int n;
	double ans;
	while (~scanf("%d",&n)&&n) {
		for (int i=0;i<n;i++) {
			scanf("%lf%lf%lf%lf",&x1[i],&y1[i],&x2[i],&y2[i]);
			x[i<<1]=x1[i]; x[(i<<1)+1]=x2[i]; y[i<<1]=y1[i]; y[(i<<1)+1]=y2[i];
		}
		sort(x,x+(n<<1)); sort(y,y+(n<<1));
		int m1=unique(x,x+(n<<1))-x-1,m2=unique(y,y+(n<<1))-y-1;
		ans=0;
		for (int i=0;i<m1;i++)
			for (int j=0;j<m2;j++)
				for (int k=0;k<n;k++)
					if (x1[k]<=x[i]&&x2[k]>=x[i+1]&&y1[k]<=y[j]&&y2[k]>=y[j+1]) {
						ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
						break;
					}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",++t,ans);
	}
}
