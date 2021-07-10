#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int K=18;
int k,q;
char s[1<<K];
struct Node
{
    int l,r;
    int v;
    char ch;
}tree[(1<<K)*4];
int id[(1<<K)*4],tot;
void push_up(int i)
{
    if(tree[i].ch=='0') tree[i].v=tree[i*2].v;
    else if(tree[i].ch=='1') tree[i].v=tree[i*2+1].v;
    else if(tree[i].ch=='?') tree[i].v=tree[i*2].v+tree[i*2+1].v;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].v=1;
        return;
    }
    id[tot++]=i;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
int main()
{
    scanf("%d",&k);
    scanf("%s",s);
    build(1,1,1<<k);
    sort(id,id+tot,[=](const int &x,const int &y){return tree[x].r-tree[x].l+1==tree[y].r-tree[y].l+1?tree[x].l<tree[y].l:tree[x].r-tree[x].l+1<tree[y].r-tree[y].l+1;});
    for(int i=0;i<(1<<k)-1;i++)
        tree[id[i]].ch=s[i];
    build(1,1,1<<k);
    scanf("%d",&q);
    while(q--)
    {
        int p;
        scanf("%d",&p);
        char c=getchar();
        while(c!='0'&&c!='1'&&c!='?') c=getchar();
        int x=id[p-1];
        tree[x].ch=c;
        for(int i=x;i>=1;i/=2)
            push_up(i);
        printf("%d\n",tree[1].v);
    }
    return 0;
}