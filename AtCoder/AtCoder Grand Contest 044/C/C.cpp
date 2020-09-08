#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int M=15,N=600005;
int n,m,Q;
char s[N];
int Pw[M];
struct Trie
{
	struct Node
	{
		int ch[3];
		int val;
		int tag;
		Node()
		{
			ch[0]=ch[1]=ch[2]=0;
			val=-1;
			tag=0;
			return;
		}
	}trie[N*3];
	int tot=1;
	void insert(int x)
	{
		vector<int>v;
		int t=x;
		while(t)
			v.push_back(t%3),t/=3;
		while(v.size()<m)
			v.push_back(0);
		int u=1;
		for(int c:v)
		{
			if(!trie[u].ch[c]) trie[u].ch[c]=++tot;
			u=trie[u].ch[c];
		}
		trie[u].val=x;
		return;
	}
	void push_down(int u)
	{
		if(!trie[u].tag) return;
		swap(trie[u].ch[1],trie[u].ch[2]);
		for(int i=0;i<3;i++)
			trie[trie[u].ch[i]].tag^=1;
		trie[u].tag=0;
		return;
	}
	void reverse(int u)
	{
		trie[u].tag^=1;
		return;
	}
	void add(int u)
	{
		if(!u) return;
		push_down(u);
		int t=trie[u].ch[2];
		trie[u].ch[2]=trie[u].ch[1];
		trie[u].ch[1]=trie[u].ch[0];
		trie[u].ch[0]=t;
		add(trie[u].ch[0]);
		return;
	}
	void query(int u,int sum,int dep,vector<int>&res)
	{
		if(!u) return;
		push_down(u);
		if(trie[u].val!=-1) res[trie[u].val]=sum;
		for(int i=0;i<3;i++)
			query(trie[u].ch[i],sum+i*Pw[dep],dep+1,res);
		return;
	}
}T;
int main()
{
	scanf("%d",&m);
	Pw[0]=1;
	for(int i=1;i<=m;i++)
		Pw[i]=Pw[i-1]*3;
	n=Pw[m];
	scanf("%s",s+1);
	Q=strlen(s+1);
	for(int i=0;i<n;i++)
		T.insert(i);
	for(int i=1;i<=Q;i++)
		if(s[i]=='S') T.reverse(1);
		else if(s[i]=='R') T.add(1);
	vector<int>res;
	res.resize(n);
	T.query(1,0,0,res);
	for(int u:res)
		printf("%d ",u);
	return 0;
}
