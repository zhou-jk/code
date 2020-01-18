#define N 500
#define M 500
#define D 10

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int d[N+1],len[M],t1[M],t2[M],in[M][D],out[M][D];
bool vis[M];
char s[N];

int main() {
	int test,n,m,t;
	freopen("calc.in","r",stdin); freopen("calc.out","w",stdout);
	for (scanf("%d",&test);test;test--) {
		memset(d,127,sizeof d);
		memset(vis,true,sizeof vis);
		scanf("%d%d%d%s",&m,&n,&t,s);
		t--;
		for (int i=0;i<n;i++)
			if (s[i]=='1') d[i]=0;
		for (int i=0;i<m;i++) {
			scanf("%d%d",&len[i],&t1[i]);
			for (int j=0;j<t1[i];j++) {
				scanf("%d",&in[i][j]);
				in[i][j]--;
			}
			scanf("%d",&t2[i]);
			for (int j=0;j<t2[i];j++) {
				scanf("%d",&out[i][j]);
				out[i][j]--;
			}
		}
		for (int i=0;i<m;i++) {
			int p=-1,k,s,s1;
			for (int j=0;j<m;j++) 
				if (vis[j]) {
					s=0;
					for (k=0;k<t1[j];k++) {
						//printf("$%d %d %d %d %d %d %d\n",j,in[j][k],d[in[j][k]],d[n],s,len[j],s1);
						if (d[in[j][k]]==d[n]) break;
						s=max(s,d[in[j][k]]);
					}
					if ((k==t1[j]||d[in[j][k]]!=d[n])&&(p<0||s+len[j]<s1)) {
						p=j;
						s1=s+len[j];
					}
				}
			if (p<0) break;
			vis[p]=false;
			for (int j=0;j<t2[p];j++){
				//printf("%d %d\n",p,out[p][j]);
				if (d[out[p][j]]==d[n]) d[out[p][j]]=s1;
			}
			if (d[t]!=d[n]) break;
		}
		if (d[t]==d[n]) printf("-1\n");
		else printf("%d\n",d[t]);
	}
	return 0;
}
