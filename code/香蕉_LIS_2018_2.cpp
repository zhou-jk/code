//VOJ 2018年寒假网赛第四场 G
#include <cstdio>
#include <algorithm>

using namespace std;

const int N=180; 
int x[N],y[N],z[N],p[N],f[N],t;

bool cmp(int k1,int k2) {
	return x[k1]>x[k2];
}

int main() {
	int n,ans;
	while (~scanf("%d",&n)&&n) { 
		for (int i=0;i<n;i++) {
			scanf("%d%d%d",&x[i*6],&y[i*6],&z[i*6]);
			x[i*6+1]=x[i*6]; y[i*6+1]=z[i*6]; z[i*6+1]=y[i*6];
			x[i*6+2]=y[i*6]; y[i*6+2]=x[i*6]; z[i*6+2]=z[i*6];
			x[i*6+3]=y[i*6]; y[i*6+3]=z[i*6]; z[i*6+3]=x[i*6];
			x[i*6+4]=z[i*6]; y[i*6+4]=x[i*6]; z[i*6+4]=y[i*6];
			x[i*6+5]=z[i*6]; y[i*6+5]=y[i*6]; z[i*6+5]=x[i*6];
		}
		n*=6;
		for (int i=0;i<n;i++) p[i]=i;
		sort(p,p+n,cmp);
		ans=0;
		for (int i=0;i<n;i++) {
			f[i]=0;
			for (int j=0;x[p[j]]>x[p[i]];j++)
				if (y[p[j]]>y[p[i]]) f[i]=max(f[i],f[j]);
			f[i]+=z[p[i]];
			ans=max(ans,f[i]);
		}
		printf("Case %d: maximum height = %d\n",++t,ans);
	}
	return 0;
}
