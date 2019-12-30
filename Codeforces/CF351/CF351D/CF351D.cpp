#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100000;
int n,Q;
struct Binary_Indexed_Tree
{
    int tree[N+1];
    Binary_Indexed_Tree()
    {
        memset(tree,0,sizeof(tree));
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        if(x==0) return;
        for(int i=x;i<=N;i+=lowbit(i))
            tree[i]+=y;
        return;
    }
    void add(int a,int b,int val)
    {
        if(a>b) return;
        add(a,val);
        add(b+1,-val);
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=tree[i];
        return res;
    }
}T1,T2;
struct Ask
{
    int l,r,id;
    bool operator < (const Ask& b) const
    {
        return r<b.r;
    }
}query[N+1];
int a[N+1],book[N+1];
int ans[N+1];
vector<int> pos[N+1];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=N;i++)
        pos[i].push_back(0);
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        scanf("%d%d",&query[i].l,&query[i].r);
        query[i].id=i;
    }
    sort(query+1,query+Q+1);
    int j=1;
    for(int i=1;i<=n&&j<=Q;i++)
    {
        int v=a[i];
        pos[v].push_back(i);
        int p=pos[v].size()-1;
        T2.add(pos[v][p-1]+1,i,1);
        if(p==1) book[i]=1;
        else
        {
            if(p==2||pos[v][p]-pos[v][p-1]==pos[v][p-1]-pos[v][p-2]) book[i]=book[pos[v][p-1]];
            else
            {
                book[i]=pos[v][p-2]+1;
                T2.add(book[pos[v][p-1]],book[i]-1,-1);
            }
        }
        T1.add(pos[v][p-1]+1,i,1);
        while(j<=Q&&query[j].r==i)
        {
            ans[query[j].id]=T1.getsum(query[j].l);
            if(T2.getsum(query[j].l)==0) ans[query[j].id]++;
            j++;
        }
    }
    for(int i=1;i<=Q;i++)
        printf("%d\n",ans[i]);
    return 0;
}