#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200001;
int T,n;
int a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1,greater<int>());
		n=unique(a+1,a+n+1)-a-1;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]&1) continue;
			while(!(a[i]&1))
			{
				a[i]>>=1;
				ans++;
				if(a[i]&1) break;
				int p=lower_bound(a+i+1,a+n+1,a[i],greater<int>())-a;
				if(p<i||p>n) continue;
				else if(a[p]!=a[i]) continue;
				else break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}