//Virtual Judge 2018年寒假网赛第二场 F 
#include <cstdio>
#include <cstring> 
#include <algorithm>

using namespace std;

long long ans;
bool vis[100];

int main() {
	int n,b[100];
	char s[101],t[101];
	scanf("%d%s",&n,&s);
	strcpy(t,s);
	for (int i=0;i<n;i++) {
		scanf("%d",&b[i]);
		ans+=b[i];
	}
	for (int i=0;i<n;i++)
		if (t[i]==t[n-i-1]) {
			//printf("%d\n",f[i]);
			int k=-1;
			for (int j=i+1;j<n;j++) 
				if (t[j]==t[n-j-1]&&t[j]!=t[i]&&(k<0||b[j]<b[k])) k=j;
			if (k<0)
				for (int j=0;j<n;j++)
					if (t[j]!=t[i]&&t[n-j-1]!=t[i]&&(k<0||b[j]<b[k])) k=j;
	    	if (b[i]<b[n-i-1]) {
	    		swap(t[i],t[k]);
	    		if (!vis[i]) {
	    			ans-=b[i];
	    			vis[i]=true;
				}
			}
			else {
				swap(t[n-i-1],t[k]);
				if (!vis[n-i-1]) {
					ans-=b[n-i-1];
					vis[n-i-1]=true;
				}
			}
			if (!vis[k]) {
				ans-=b[k];
				vis[k]=true;
			}
			if (t[k]==s[k]&&vis[k]) {
				ans+=b[k];
				vis[k]=false;
			}
		}
	printf("%lld",ans);
	return 0;
}
