//Virtual Judge 2018年寒假网赛第三场 H
#define N 1000

#include <cstdio>
#include <algorithm>

using namespace std;

int n,a[N],b[N],f[N],p[N],r[N],ans;

void output(int k) {
	if (k>p[k]) output(p[k]);
	printf("%d\n",r[k]+1);
}

bool cmp(int x,int y) {
	return a[x]<a[y];
}

int main() {
	while (~scanf("%d%d",&a[n],&b[n])) r[n]=n++;
	sort(r,r+n,cmp);
	for (int i=0;i<n;i++) {
		p[i]=i;
		for (int j=0;j<i;j++)
			if (a[r[j]]<a[r[i]]&&b[r[j]]>b[r[i]]&&f[j]>f[i]) {
				f[i]=f[j]; p[i]=j;
			}
		f[i]++;
		if (f[i]>f[ans]) ans=i;
	}
	printf("%d\n",f[ans]);
	output(ans);
	return 0;
}
