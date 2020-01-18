//VOJ 2018年寒假网赛第四场 H
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=100,S1=100,S2=100;//N:技能数 S1:血量 S2:魔法值 
int a[N],b[N],f[2*S1+1][S2+1];

int main() {
	int n,t,q,ans;
	while (~scanf("%d%d%d",&n,&t,&q)&&(n||t||q)) {
		for (int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
		a[n]=0; b[n]=1;
		memset(f,127,sizeof f); f[2*S1][S2]=0;
		for (int i=2*S1-1;i>=0;i--) {
			for (int j=t;j<S2;j++) {
				for (int k=0;k<=n;k++)
					if (S2-(j-t)>=a[k]&&2*S1-i>=b[k]) f[i][j]=min(f[i][j],f[i+b[k]][j-t+a[k]]);
				f[i][j]++;
				//printf("&%d %d %d",i,j,f[i][j]);
			}
			for (int j=0;j<=t;j++)
				for (int k=0;k<=n;k++)
					if (j>=a[k]&&2*S1-i>=b[k]) f[i][S2]=min(f[i][S2],f[i+b[k]][S2-j+a[k]]);
			f[i][S2]++;
			//printf("&%d %d %d\n",i,S2,f[i][S2]);
		}
	    ans=S1;
	    for (int i=0;i<=S1;i++)
			for (int j=t;j<=S2;j++) ans=min(ans,f[i][j]);
		//printf("%d\n",ans);
		if ((ans-1)*q>=S1) puts("My god");
		else printf("%d\n",ans);
	}
	return 0;
}
