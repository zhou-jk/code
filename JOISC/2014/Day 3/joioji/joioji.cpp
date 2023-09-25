#include<iostream> 
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
char s[N];
int J[N],O[N],I[N];
map<pair<int,int>,int>book; 
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        J[i]=J[i-1]+(s[i]=='J');
        O[i]=O[i-1]+(s[i]=='O');
        I[i]=I[i-1]+(s[i]=='I');
    }
    book[make_pair(0,0)]=0; 
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int p1=J[i]-O[i],p2=O[i]-I[i];
        if(book.count(make_pair(p1,p2))) ans=max(ans,i-book[make_pair(p1,p2)]);
        else book[make_pair(p1,p2)]=i;
    }
    printf("%d",ans);
    return 0;
}