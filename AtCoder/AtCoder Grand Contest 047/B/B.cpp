#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005,M=1000005;
int n;
struct Trie
{
	int ch[26];
	int siz;
	int col[26];
}trie[M];
int tot=1;
void insert(const string &s)
{
	int len=s.size();
	int u=1;
	trie[u].siz++;
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a';
		if(!trie[u].ch[c]) trie[u].ch[c]=++tot;
		u=trie[u].ch[c];
		trie[u].siz++;
	}
	return;
}
int res;
void dfs(int u,int c)
{
	if(!u) return;
	if(c!=-1) trie[u].col[c]=trie[u].siz;
	for(int i=0;i<26;i++)
	{
		if(!trie[u].ch[i]) continue;
		dfs(trie[u].ch[i],i);
		for(int j=0;j<26;j++)
			if(j!=c) trie[u].col[j]+=trie[trie[u].ch[i]].col[j];
	}
	return;
}
int query(const string &s)
{
	int len=s.size();
	int u=1;
	for(int i=0;i<len-1;i++)
	{
		int c=s[i]-'a';
		if(!trie[u].ch[c]) return 0;
		u=trie[u].ch[c];
	}
	res=trie[u].col[s[len-1]-'a']-1;
	return res;
}
string s[N];
int main()
{
	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int len=s[i].size();
		reverse(s[i].begin(),s[i].end());
		insert(s[i]);
	}
	dfs(1,-1);
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=query(s[i]);
	printf("%lld",ans);
	return 0;
}
