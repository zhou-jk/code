#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int tot,root;
struct Node
{
	int fa,val,size,num,ch[2];
	Node()
	{
		fa=val=size=num=ch[0]=ch[1]=0;
		return;
	}
	void clear()
	{
		fa=val=size=num=ch[0]=ch[1]=0;
		return;
	}
}tree[N];
int get(int u)
{
	return tree[tree[u].fa].ch[1]==u;
}
void push_up(int u)
{
	if(!u) return;
	tree[u].size=tree[u].num;
	if(tree[u].ch[0]) tree[u].size+=tree[tree[u].ch[0]].size;
	if(tree[u].ch[1]) tree[u].size+=tree[tree[u].ch[1]].size;
	return;
}
void connect(int u,int v,int pos)
{
	if(u) tree[u].fa=v;
	if(v) tree[v].ch[pos]=u;
	return;
}
void rotate(int u)
{
	int f=tree[u].fa,gf=tree[f].fa,r=get(u),gr=get(f);
	connect(tree[u].ch[r^1],f,r);
	connect(f,u,r^1);
	connect(u,gf,gr);
	push_up(f);
	push_up(u);
	return;
}
void splay(int u)
{
	while(tree[u].fa)
	{
		int f=tree[u].fa;
		if(tree[f].fa) rotate(get(u)==get(f)?f:u);
		rotate(u);
	}
	root=u;
	return;
}
void ins(int x)
{
	if(!root)
	{
		root=++tot;
		tree[root].val=x;
		tree[root].fa=0;
		tree[root].size=tree[root].num=1;
		tree[root].ch[0]=tree[root].ch[1]=0;
		return;
	}
	int now=root,f=0;
	while(1)
	{
		if(tree[now].val==x)
		{
			tree[now].num++;
			push_up(now);
			push_up(f);
			splay(now);
			return; 
		}
		f=now,now=tree[f].ch[x>tree[f].val];
		if(!now)
		{
			now=++tot;
			tree[now].val=x;
			tree[now].size=tree[now].num=1;
			tree[now].fa=f;
			tree[now].ch[0]=tree[now].ch[1]=0;
			tree[f].ch[x>tree[f].val]=now;
			push_up(f);
			splay(now);
			return;
		}
	}
	return;
}
int find(int x)
{
	int now=root,res=1;
	while(1)
	{ 
		if(tree[now].ch[0]&&x<tree[now].val)
		{
			now=tree[now].ch[0];
			continue;
		}
		if(tree[now].ch[0]) res+=tree[tree[now].ch[0]].size;
		if(x==tree[now].val)
		{
			splay(now);
			return res;
		}
		res+=tree[now].num;
		now=tree[now].ch[1];
	}
}
int findkth(int x)
{
	int now=root;
	while(1)
	{
		if(tree[now].ch[0]&&x<=tree[tree[now].ch[0]].size)
		{
			now=tree[now].ch[0];
			continue;
		}
		if(tree[now].ch[0]) x-=tree[tree[now].ch[0]].size;
		if(x<=tree[now].num)
		{
			splay(now);
			return tree[now].val;
		}
		x-=tree[now].num;
		now=tree[now].ch[1];
	}
}
int pre(int u)
{
	int now=tree[u].ch[0];
	while(tree[now].ch[1])
		now=tree[now].ch[1];
	return now;
}
int nxt(int u)
{
	int now=tree[u].ch[1];
	while(tree[now].ch[0])
		now=tree[now].ch[0];
	return now;
}
void del(int x)
{
	int pos=find(x);
	if(tree[root].num>1)
	{
		tree[root].num--;
		push_up(root);
		return; 
	}
	if(!tree[root].ch[0]&&!tree[root].ch[1])
	{
		tree[root].clear();
		root=0;
		return;
	}
	if(!tree[root].ch[0])
	{
		int tmp=tree[root].ch[1];
		tree[tmp].fa=0;
		tree[root].clear();
		root=tmp;
		return;
	}
	if(!tree[root].ch[1])
	{
		int tmp=tree[root].ch[0];
		tree[tmp].fa=0;
		tree[root].clear();
		root=tmp;
		return;
	}
	int tmp=root,left=pre(root);
	splay(left);
	connect(tree[tmp].ch[1],root,1);
	tree[tmp].clear();
	push_up(root);
	return; 
}
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(op==1) ins(x);
		else if(op==2) del(x);
		else if(op==3) printf("%d\n",find(x));
		else if(op==4) printf("%d\n",findkth(x));
		else if(op==5)
		{
			ins(x);
			printf("%d\n",tree[pre(root)].val);
			del(x);
		}
		else if(op==6)
		{
			ins(x);
			printf("%d\n",tree[nxt(root)].val);
			del(x);
		}
	}
	return 0;
}