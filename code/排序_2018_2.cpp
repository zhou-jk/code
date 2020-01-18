//VOJ 2018年寒假网赛第七场 A
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int LEN=1000,N=(LEN+1)>>1;
int num[N],t;
bool vis[N];
char s[LEN+1];

int main() {
	while (~scanf("%s",s)) {
		memset(vis,false,sizeof vis); memset(num,0,sizeof num); t=0;
		for (int i=0;s[i];i++)
			if (s[i]=='5') {
				if (vis[t]) t++;
			}
			else {
				num[t]=num[t]*10+s[i]-'0';
				vis[t]=true;
			}
		if (vis[t]) t++;
		sort(num,num+t);
		for (int i=0;i<t-1;i++) printf("%d ",num[i]);
		printf("%d\n",num[t-1]);
	}
	return 0;
}