#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500001;
int n;
char s[N];
struct Edge
{
	int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int Max,ans;
int fail[N];
void kmp()
{
    int j=0;
    for(int i=2;i<=n;i++)
    {
		while(j&&s[j+1]!=s[i]) j=fail[j];
		if(s[j+1]==s[i]) j++;
        fail[i]=j;
	}
    return;
}
int pre[N],nxt[N];
bool book[N];
void del(int u)
{
	pre[nxt[u]]=pre[u],nxt[pre[u]]=nxt[u];
	Max=max(Max,nxt[u]-pre[u]);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        del(v);
    }
    return;
}
void dfs(int u)
{
    if(u>=Max)
    {
        ans=u;
        return;
    }
	int to=0;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(book[v]) to=v;
        else del(v);
    }
	dfs(to);
    return;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
    kmp();
    for(int i=1;i<=n;i++)
		add_edge(fail[i],i),pre[i]=i-1,nxt[i]=i+1;
	nxt[n]=0;
    Max=1;
    for(int i=n;i;i=fail[i])
        book[i]=true;
	dfs(0);
    printf("%d",ans);
	return 0;
}