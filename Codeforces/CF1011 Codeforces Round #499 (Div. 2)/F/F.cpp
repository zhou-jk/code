#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
string s[N];
int v[N];
int ch[N][2];
int fa[N];
void dfs1(int u)
{
	if(s[u]=="IN") return;
	dfs1(ch[u][0]);
	if(s[u]!="NOT") dfs1(ch[u][1]);
	if(s[u]=="AND") v[u]=v[ch[u][0]]&v[ch[u][1]];
	else if(s[u]=="OR") v[u]=v[ch[u][0]]|v[ch[u][1]];
	else if(s[u]=="XOR") v[u]=v[ch[u][0]]^v[ch[u][1]];
	else if(s[u]=="NOT") v[u]=!v[ch[u][0]];
	return;
}
int tag[N];
int res[N];
void dfs2(int u)
{
	if(s[u]=="AND")
	{
		if(v[ch[u][0]]==0) tag[ch[u][1]]=true;
		if(v[ch[u][1]]==0) tag[ch[u][0]]=true;
	}
	else if(s[u]=="OR")
	{
		if(v[ch[u][0]]==1) tag[ch[u][1]]=true;
		if(v[ch[u][1]]==1) tag[ch[u][0]]=true;
	}
	if(s[u]=="IN")
	{
		if(tag[u]) res[u]=v[1];
		else res[u]=!v[1];
		return;
	}
	tag[ch[u][0]]|=tag[u],dfs2(ch[u][0]);
	if(s[u]!="NOT") tag[ch[u][1]]|=tag[u],dfs2(ch[u][1]);
	return;
}
int main()
{
	cin>>n;
	s[0]="IN";
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=="AND"||s[i]=="OR"||s[i]=="XOR") cin>>ch[i][0]>>ch[i][1],fa[ch[i][0]]=fa[ch[i][1]]=i;
		else if(s[i]=="NOT") cin>>ch[i][0],fa[ch[i][0]]=i;
		else if(s[i]=="IN") cin>>v[i]; 
	}
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=n;i++)
		if(s[i]=="IN") printf("%d",res[i]);
	return 0;
}
