#define N 2000

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[N][8];
int d[N];
bool v[N];

int calc(char *a,char *b) {
	int r=0;
	for (int i=0;i<7;i++)
		if (a[i]!=b[i]) r++;
	return r;
}

int main() {
	freopen("connect.in","r",stdin); freopen("connect.out","w",stdout);
	int n,ans;
	while (~scanf("%d",&n)&&n) {
		for (int i=0;i<n;i++) scanf("%s",s[i]);
    	memset(d,127,sizeof d); memset(v,1,sizeof v);
		d[0]=0; ans=0;
		for (int i=0;i<n;i++) {
			int k=-1;
			for (int j=0;j<n;j++)
				if (v[j]&&(k<0||d[j]<d[k])) k=j;
			v[k]=false;
			ans+=d[k];
			for (int j=1;j<n;j++) 
				if (v[j]) d[j]=min(d[j],calc(s[k],s[j]));
		}
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	return 0;
}
