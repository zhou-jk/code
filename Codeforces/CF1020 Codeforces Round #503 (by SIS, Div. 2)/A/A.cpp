#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,h,a,b,k;
void solve()
{
	int ta,fa,tb,fb;
	scanf("%d%d%d%d",&ta,&fa,&tb,&fb);
	int ans=min({abs(fa-a)+abs(fb-b)+abs(a-b),abs(fa-a)+abs(fb-a),abs(fa-b)+abs(fb-a)+abs(a-b),abs(fa-b)+abs(fb-b)})+abs(ta-tb);
	if(a<=fa&&fa<=b) ans=min(ans,abs(fb-fa)+abs(ta-tb));
	if(a<=fb&&fb<=b) ans=min(ans,abs(fb-fa)+abs(ta-tb));
	if(ta==tb) ans=min(ans,abs(fa-fb));
	printf("%d\n",ans);
	return;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
	while(k--)
		solve();
	return 0;
}
