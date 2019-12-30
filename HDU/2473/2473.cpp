#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000005;
int n,m;
int fa[N],book[N];
bool num[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    fa[v]=getf(fa[v]);
    return fa[v];
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) fa[f2]=f1;
    return;
}
int main()
{
    int Case=0;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) return 0;
        for(int i=0;i<n;i++)
            fa[i]=i,book[i]=i;
        memset(num,false,sizeof(num));
        int k=n;
        while(m--)
        {
            char ch;
            for(ch=getchar();ch!='M'&&ch!='S';ch=getchar());
            if(ch=='M')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                merge(book[a],book[b]);
            }
            else if(ch=='S')
            {
                int a;
                scanf("%d",&a);
                book[a]=k;
                fa[k]=k;
                k++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int t=getf(book[i]);
            if(!num[t]) ans++,num[t]=true;
        }
        printf("Case #%d: %d\n",++Case,ans);
    }
    return 0;
}