#include <bits\stdc++.h>

using namespace std;

int const N=100003;
int n,a,b,x[N];
set<int> s;
set<int>::iterator p;

int check(int mid) {
	if (abs(a-b)>mid) return 0;
	s.clear();
	s.insert(a);
	for (int i=1;i<=n;i++) {
		int low=x[i]-mid;
		int high=x[i]+mid;
		if (abs(x[i]-x[i-1]<=mid)) s.insert(x[i-1]);
		while (!s.empty()&& *(p=s.begin())<low) s.erase(p);
		while (!s.empty()&&*(p=--s.end())>high) s.erase(p);
		printf("%d %d\n",mid,i);
		if (s.empty()) return 0;
	}
	return 1;
}

int main() {
	scanf("%d%d%d",&n,&a,&b);
	x[0]=b;
	for (int i=1;i<=n;i++) scanf("%d",x+i);
	int l=abs(a-b),r=(int)1e9;
	while (l<r) {
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}

