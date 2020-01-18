#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int a[1001];
int ans,e[1001][1001],in[1001];
bool book[1001],vis[1001];
queue<int>q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
    {
		memset(book,false,sizeof(book));
        int s;
		scanf("%d",&s);
		for(int j=1;j<=s;j++)
        {
			scanf("%d",&a[j]);
			book[a[j]] = true;
		}
		for(int j=a[1];j<=a[s];j++)
        {
			if(!book[j])
            {
				for(int k=1;k<=s;k++)
				    if(!e[j][a[k]])
                    {
				    	e[j][a[k]] = 1;
				    	in[a[k]]++;
					}
			}
		}
	}
    for(int i=1;i<=n;i++)
        if(in[i]==0&&!vis[i]) q.push(i),vis[i]=true;
    while(!q.empty())
    {
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int v=1;v<=n;v++)
                if(e[u][v]) in[v]--;
        }
        for(int i=1;i<=n;i++)
            if(in[i]==0&&!vis[i]) q.push(i),vis[i]=true;
        ans++;
    }
	printf("%d",ans);
    return 0;
}