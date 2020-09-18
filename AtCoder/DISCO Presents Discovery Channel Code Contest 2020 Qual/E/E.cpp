#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=205;
int n;
int query(const vector<int>&A)
{
	cout<<"? ";
	for(int u:A)
		cout<<u<<" ";
	cout<<endl;
	string s;
	cin>>s;
	if(s=="Red") return 1;
	else if(s=="Blue") return 0;
	else return -1;
}
vector<int> build(int l,int r)
{
	vector<int>res;
	for(int i=l;i<=r;i++)
		res.push_back(i);
	return res;
}
vector<int> operator+(const vector<int>&a,const vector<int>&b)
{
	vector<int>res;
	for(int u:a)
		res.push_back(u);
	for(int u:b)
		res.push_back(u);
	return res;
}
char ans[N];
int res[N];
int get(int u)
{
	if(res[u]!=-1) return res[u];
	else return res[u]=query(build(u,u+n-1));
}
int main()
{
	cin>>n;
	int l=1,r=n+1;
	memset(res,-1,sizeof(res));
	while(l<r-1)
	{
		int mid=(l+r)/2;
		auto check=[=](int x)->bool{return get(l)==get(x);};
		if(check(mid)) l=mid;
		else r=mid;
	}
	int L=l+1,R=l+n-1;
	vector<int>add=build(L,R);
	vector<int>posr,posb;
	for(int i=1;i<=L-1;i++)
		if(query((vector<int>){i}+add)) ans[i]='R',posr.push_back(i);
		else ans[i]='B',posb.push_back(i);
	for(int i=R+1;i<=n*2;i++)
		if(query(add+(vector<int>){i})) ans[i]='R',posr.push_back(i);
		else ans[i]='B',posb.push_back(i);
	vector<int>q;
	for(int i=0;i<n/2;i++)
		q.push_back(posr[i]),q.push_back(posb[i]);
	for(int i=L;i<=R;i++)
		if(query(q+(vector<int>){i})) ans[i]='R';
		else ans[i]='B';
	cout<<"! ";
	for(int i=1;i<=n*2;i++)
		cout<<ans[i];
	cout<<endl;
	return 0;
}
