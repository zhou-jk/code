#include<iostream>
#include<cstdio>
const int N=300001;
int n,m,Q;
int ch[N*35][2],c[N*35];
int root[N],st1[N],st2[N],tot;
long long sl[N],zl[N];
int update(int rt,int u,int va)
{
    int tmp,rt1;tmp=rt1=++tot;
    for (int i=31;i>=0;i--)
    {
        ch[rt1][0]=ch[rt][0];ch[rt1][1]=ch[rt][1];
        c[rt1]=c[rt]+va;
        int t=(u&(1<<i))>>i;
        ch[rt1][t]=++tot;
        rt1=ch[rt1][t];
        rt=ch[rt][t];
    }
    c[rt1]=c[rt]+va;
    return tmp;
}
long long query(int L,int R,int l,int r,int u)
{
    long long ans=0;
    for(int i=L;i<=R;i++)
        st1[i]=root[l],st2[i]=root[r];
    for(int k=31;k>=0;k--)
    {
        int sum=0;
        for(int i=L;i<=R;i++)
        {
            long long t=(sl[i]&(1<<k))>>k;
            sum+=c[ch[st2[i]][t^1]]-c[ch[st1[i]][t^1]];
        }
        if(sum<u)
        {
            u-=sum;
            for(int i=L;i<=R;i++)
            {
                long long t=(sl[i]&(1<<k))>>k;
                st2[i]=ch[st2[i]][t];
                st1[i]=ch[st1[i]][t];
            }
        }
        else
        {
            for(int i=L;i<=R;i++)
            {
                long long t=(sl[i]&(1<<k))>>k;
                st2[i]=ch[st2[i]][t^1];
                st1[i]=ch[st1[i]][t^1];
            }
            ans|=(1<<k);
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m); 
    for(int i=1;i<=n;i++)
        scanf("%lld",&sl[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld",&zl[i]);
    for(int i=1;i<=m;i++)
        root[i]=update(root[i-1],zl[i],1);
    scanf("%d",&Q);
    while(Q--)
    {
        int u,d,l,r,k;
        scanf("%d%d%d%d%d",&u,&d,&l,&r,&k);
        printf("%lld\n",query(u,d,l-1,r,k));
    }
    return 0; 
}