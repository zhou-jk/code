#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=1061109567;
vector<int>e;
int n;
int d[150],s=INF;
bool book[1001];
char ch[1001][5];
struct Node
{
    int to,id;
};
vector<Node>g[150]; 
bool cmp(Node a,Node b)
{
    return a.to<b.to;
}
void dfs(int i)
{
    for(int k=0;k<g[i].size();k++)
    {
        int v=g[i][k].to,id=g[i][k].id;
        if(book[id]) continue;
        book[id]=true;
        dfs(v);
    }
    e.push_back(i);
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ch[i]);
        g[ch[i][0]].push_back((Node){ch[i][1],i});
        g[ch[i][1]].push_back((Node){ch[i][0],i});
        d[ch[i][1]]++,d[ch[i][0]]++;
        s=min(s,(int)ch[i][0]),s=min(s,(int)ch[i][1]);
    }
    for(int i='A';i<='z';i++)
        sort(g[i].begin(),g[i].end(),cmp);
    int cnt=0;
    for(int i='A';i<='z';i++)
        if(d[i]%2==1)
        {
            if(cnt==0) s=INF;
            cnt++,s=min(s,i);
        }
    if(cnt!=0&&cnt!=2)
    {
        printf("No Solution");
        return 0;
    }
    memset(book,false,sizeof(book));
    dfs(s);
    if(e.size()==n+1)
        for(int i=e.size()-1;i>=0;i--)
            printf("%c",e[i]);
    else printf("No Solution");
    return 0;
}