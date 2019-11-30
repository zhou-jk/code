#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const int N=100001;
int n;
int f[N];
map<pair<int,int>,int>book;
vector<int>pre[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y=n-y;  
        if(x>y) continue;
        book[make_pair(x,y)]++;
        if(book[make_pair(x,y)]==1) pre[y].push_back(x);
    }    
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        for(auto j:pre[i])
            f[i]=max(f[j-1]+min(book[make_pair(j,i)],i-j+1),f[i]);
    }
    printf("%d",n-f[n]);
    return 0;
}