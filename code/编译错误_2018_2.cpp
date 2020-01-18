//VOJ 2018年寒假网赛第五场 B
#include <cstdio>
#include <algorithm>

using namespace std;

const int N=100000;
int a[N],b[N-1],c[N-2];

int solve(int *a,int *b,int n) {
	for (int i=0;i<n-1;i++)
		if (a[i]<b[i]) return a[i];
	return a[n-1];
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n-1;i++) scanf("%d",&b[i]);
	for (int i=0;i<n-2;i++) scanf("%d",&c[i]);
	sort(a,a+n); sort(b,b+n-1); sort(c,c+n-2);
	printf("%d\n%d",solve(a,b,n),solve(b,c,n-1));
	return 0;
}
