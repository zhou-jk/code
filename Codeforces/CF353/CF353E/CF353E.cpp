#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000001;
string s;
int cnt;
bool book[N];
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
        if(i==0||s[i]^s[i-1]) book[++cnt]=true;
        else book[cnt]=false;
	if(s[0]==s[s.size()-1]) book[1]=0,cnt--;
	int tot=0,ans=0;
	for(int i=1;i<=cnt;i++)
		if(book[i]) tot++;
		else ans+=tot/2+1,tot=0;
    printf("%d",ans+tot/2);
	return 0;
}