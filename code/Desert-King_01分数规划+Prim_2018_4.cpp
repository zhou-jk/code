//POJ 2728
#include <cstdio>
#include <cstring>
#include <cmath>

using std::abs;

const int N=1000,NUM=10000000;
int x[N],y[N],z[N],n;
double edge1[N][N],edge2[N][N],dist[N];
bool vis[N];

void build_edge(double a)
{
	for (int i=0; i<n; i++)
		for (int j=0; j<=i; j++)
			edge2[j][i]=edge2[i][j]=abs(z[i]-z[j]*1.0)-a*edge1[i][j];
}

double prim()
{
	double ret=0;
	memset(vis,false,sizeof vis);
	dist[0]=0;
	for (int i=1; i<n; i++) dist[i]=NUM;
	for (int i=0; i<n; i++)
	{
		int k=-1;
		for (int j=0; j<n; j++)
			if (!vis[j]&&(k<0||dist[j]<dist[k])) k=j;
		vis[k]=true;
		ret+=dist[k];
		for (int j=1; j<n; j++)
			if (edge2[k][j]<dist[j]) dist[j]=edge2[k][j];
	}
	return ret;
}

int main()
{
	while (scanf("%d",&n)!=EOF&&n)
	{
		for (int i=0; i<n; i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
		for (int i=0; i<n; i++)
			for (int j=0; j<=i; j++)
				edge1[j][i]=edge1[i][j]=sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		double l=0,r=NUM,mid;
		while (r-l>1e-6)
		{
			mid=(l+r)*0.5;
			build_edge(mid);
			if (prim()<0) r=mid;
			else l=mid;
		}
		printf("%.3f\n",l);
	}
	return 0;
}