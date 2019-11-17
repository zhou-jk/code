#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=1002;
int n,a[N];
int Min[N],color[N];
struct Edge
{
    int to,next;
}edge[N];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
stack<int>s1,s2;
bool dfs(int u)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!color[v])
        {
            color[v]=color[u]^1;
            if(!dfs(v)) return false;
        }
        else if(color[v]==color[u]) return false;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    Min[n+1]=1e9;
    for(int i=n;i>=1;i--)
        Min[i]=min(Min[i+1],a[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]>Min[j+1]&&a[i]<a[j]) add_edge(i,j),add_edge(j,i);
    for(int i=1;i<=n;i++)
        if(!color[i])
        {
            color[i]=2;
            if(!dfs(i))
            {
                printf("0");
                return 0;
            }
        }
    int tot=1;
    for(int i=1;i<=n;i++)
    { 
        if(color[i]==2)
        {
            s1.push(a[i]);
            printf("a ");
        }
        else
        {
            s2.push(a[i]);
            printf("c ");
        }
        while((!s1.empty()&&s1.top()==tot)||(!s2.empty()&&s2.top()==tot))
        {
            if(!s1.empty()&&s1.top()==tot)
            {
                printf("b ");
                s1.pop();
            }
            else
            {
                printf("d ");
                s2.pop();
            }
            tot++;
        }
    }
    return 0;
}