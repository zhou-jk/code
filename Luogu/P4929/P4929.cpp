#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct DLX
{
    static const int N=501;
    static const int M=10001;
    int tot;
    int l[M],r[M],u[M],d[M],col[M],row[M];
    int head[N];
    int size[N];
    int res[N]; 
    void init(int m)
    {
        for(int i=0;i<=m;i++)
            r[i]=i+1,l[i]=i-1,u[i]=d[i]=i;
        r[m]=0,l[0]=m;
        memset(head,-1,sizeof(head));
        memset(size,0,sizeof(size));
        tot=m;
        return;
    }
    void link(int R,int C)
    {
        size[C]++;
        tot++;
        row[tot]=R;
        col[tot]=C;
        u[tot]=C;
        d[tot]=d[C];
        u[d[C]]=tot;
        d[C]=tot;
        if(head[R]==-1) head[R]=r[tot]=l[tot]=tot;
        else
        {
            r[tot]=head[R];
            l[tot]=l[head[R]];
            r[l[head[R]]]=tot;
            l[head[R]]=tot;
        }
        return;
    }
    void remove(int C)
    {
        r[l[C]]=r[C],l[r[C]]=l[C];
        for(int i=d[C];i!=C;i=d[i])
            for(int j=r[i];j!=i;j=r[j])
                u[d[j]]=u[j],d[u[j]]=d[j],size[col[j]]--;
        return;
    }
    void restore(int C)
    {
        for(int i=u[C];i!=C;i=u[i])
            for(int j=l[i];j!=i;j=l[j])
                u[d[j]]=j,d[u[j]]=j,size[col[j]]++;
        r[l[C]]=C,l[r[C]]=C;
        return;
    }
    bool dance(int dep)
    {
        if(r[0]==0)
        {
            for(int i=1;i<dep;i++)
                printf("%d ",res[i]);
            return true;
        }
        int c=r[0];
        for(int i=r[0];i!=0;i=r[i])
            if(size[i]<size[c]) c=i;
        remove(c);
        for(int i=d[c];i!=c;i=d[i])
        {
            res[dep]=row[i];
            for(int j=r[i];j!=i;j=r[j])
                remove(col[j]);
            if(dance(dep+1)) return true;
            for(int j=l[i];j!=i;j=l[j])
                restore(col[j]);
        }
        restore(c);
        return false;
    }
}dlx;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    dlx.init(m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x;
            scanf("%d",&x);
            if(x==1) dlx.link(i,j);
        }
    if(!dlx.dance(1)) printf("No Solution!");
    return 0;
}