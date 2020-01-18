//Virtual Judge 2018年寒假网赛第三场 F
#define N 100001
#define D 201

#include <cstdio>
#include <algorithm>

using namespace std;

int l[N],d[N],p[N],s[D],sum,t1,t2,c;

bool cmp(int x,int y) {
	return l[x]<l[y];
}

int main() {
	int n,j,ans=1E9,t;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&l[i]);
		p[i]=i;
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&d[i]);
		s[d[i]]++;
	}
	sort(p+1,p+n+1,cmp);
	t=n;
	for (int i=n;i>0;i--) {
		t2++;
		s[d[p[i]]]--;
		//printf("&%d %d\n",p[i],p[i-1]);
		t1+=d[p[i]];
		if (l[p[i]]>l[p[i-1]]) {
			c=0; t2=max(t-t2*2+1,0);
			//printf("%d %d\n",t2,sum);
			for (j=1;t2>s[j];j++)
				t2-=s[j],c+=s[j]*j;
			//printf("%d\n",c);
			c+=t2*j+sum;
			//printf("%d\n",c);
			sum+=t1;
			t=i-1; t1=t2=0;
			ans=min(ans,c);
		}
	}
	printf("%d",ans);
	return 0;
}
