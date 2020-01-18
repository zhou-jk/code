//VOJ POJ 3159
#include <cstdio>
#include <cstring>

const int N=30000,M=150000;
struct Edge{
	int v,len,next;
} e[M+1];
int q[N],head[N],d[N],t,top;
bool vis[N];

inline int read()
{
	int x = 0;
	char ch=getchar(); 
	int positive=1;
	for (;ch<'0'&&ch>'9';ch=getchar()) if (ch == '-') positive=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x = x * 10 + ch - '0';
	return positive*x;
}

void add_edge(int u,int v,int len) {
	e[++t].v=v; e[t].len=len; e[t].next=head[u];
	head[u]=t;
}

int main() {
	int n,m,c,u,v,len;
	n=read(); m=read();
	for (int i=0;i<m;i++) {
		u=read(); v=read(); len=read();
		add_edge(u-1,v-1,len);
	}
	memset(d,127,sizeof d); d[0]=0;
	top=1; q[0]=0;
	while (top) {
		int tmp=q[--top];
		vis[tmp]=false;
		for (int i=head[tmp];i;i=e[i].next)
			if (d[tmp]+e[i].len<d[e[i].v]) {
				d[e[i].v]=d[tmp]+e[i].len;
				if (!vis[e[i].v]) {
					vis[e[i].v]=true;
					q[top++]=e[i].v;
				}
			}
	}
	printf("%d",d[n-1]);
	return 0;
}
