#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1000;
int c[N][N],max_x[N*N],min_x[N*N],max_y[N*N],min_y[N*N],vis[N][N],cnt;
bool used[N*N],f[N*N];

inline int read(){
    int X=0;
    bool w=false;
    char ch=0;
    while(ch<'0'||ch>'9') w|=ch=='-',ch=getchar();
    while(ch>='0'&&ch<='9') X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

int main() {
	freopen("art.in","r",stdin); freopen("art.out","w",stdout);
	int n,ans;
	n=read();
	for (int i=0;i<n*n;i++) min_x[i]=min_y[i]=n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) {
			c[i][j]=read()-1;
			if (c[i][j]>=0) {
				cnt-=used[c[i][j]];
				used[c[i][j]]=true;
				cnt+=used[c[i][j]];
				max_x[c[i][j]]=max(max_x[c[i][j]],i); min_x[c[i][j]]=min(min_x[c[i][j]],i); max_y[c[i][j]]=max(max_y[c[i][j]],j); min_y[c[i][j]]=min(min_y[c[i][j]],j);
			}
		}
	if (n>1&&cnt==1) {
		printf("%d",n*n-1);
		return 0;
	}
	for (int i=0;i<n*n;i++)
		if (used[i])
			for (int j=min_x[i];j<=max_x[i];j++)
				for (int k=min_y[i];k<=max_y[i];k++) vis[j][k]++;
	ans=n*n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (vis[i][j]>1) {
				ans+=f[c[i][j]];
				f[c[i][j]]=true;
				ans-=f[c[i][j]];
			}
	printf("%d",ans);
	return 0;
}