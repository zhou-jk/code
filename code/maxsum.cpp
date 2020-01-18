#include <cstdio>
#include <algorithm>

using namespace std;

const int N=2000;
int a[N],b[N],ans;

int main() {
	freopen("maxsum.in","r",stdin); freopen("maxsum.out","w",stdout);
	int n,tmp;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=n-1;i>=0;i--) scanf("%d",&b[i]);
	for (int i=0;i<n;i++) {
		tmp=0;
		for (int j=0;j<n-i>>1;j++) 
			tmp=max(tmp+a[j]*b[j+i]+a[n-1-i-j]*b[n-1-j],0);
			//printf("%d %d %d %d %d\n",j,j+i,n-1-i-j,n-j,a[j]*b[j+i]+a[n-1-i-j]*b[n-1+j]);
		if ((n-i)%2) tmp+=a[n-i>>1]*b[(n-i>>1)+i];
		ans=max(ans,tmp);
	}
	for (int i=0;i<n;i++) {
		tmp=0;
		for (int j=0;j<n-i>>1;j++) 
			tmp=max(tmp+b[j]*a[j+i]+b[n-1-i-j]*a[n-1-j],0);
			//printf("%d %d %d %d %d\n",j,j+i,n-1-i-j,n-j,b[j]*a[j+i]+b[n-1-i-j]*a[n-1-j]);
		if ((n-i)%2) tmp+=b[n-i>>1]*a[(n-i>>1)+i];
		ans=max(ans,tmp);
	}
	printf("%d",ans);
	return 0;
}
