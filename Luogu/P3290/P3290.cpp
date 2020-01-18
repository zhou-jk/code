#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=1000000007;
int n,m,c,q,V;  
int fa[7],nexta[7][3],fb[7],nextb[7][3],a[7],b[7];  
long long f[2][4096][7][7],cur;  
char A[7], B[7];
inline int id(char ch)
{
    if(ch=='W') return 0;
    else if(ch=='B') return 1;
    else if(ch=='X') return 2; 
}  
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
void init(int *s,int *f,int Next[7][3])
{
    for(int i=2,j=0;i<=c;i++)
    {
        while(j&&s[j+1]!=s[i]) j=f[j];
        if(s[j+1]==s[i]) j++;
        f[i]=j;
    }
    for(int i=0;i<c;i++)
        for(int j=0,k=i;j<3;j++)
        {
            while(k&&s[k+1]!=j) k=f[k];
            if(s[k+1]==j) k++;
            Next[i][j]=k;
            k=i;
        }
    return;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&c,&q); 
    V=1<<(m-c+1);  
    while(q--)  
    {
        scanf("%s%s",A+1,B+1);
        for(int i=1;i<=c;i++)
            a[i]=id(A[i]),b[i]=id(B[i]);
        init(a,fa,nexta);
        init(b,fb,nextb);
        memset(f,0,sizeof(f));
        cur=0;
        f[1][0][0][0]=1;
        for(int i=1;i<=n;i++) 
        {
            memset(f[cur],0,sizeof(f[cur]));
            for(int j=0;j<V;j++)
                for(int k=0;k<c;k++)
                    for(int l=0;l<c;l++)
                        f[cur][j][0][0]=(f[cur][j][0][0]+f[cur^1][j][k][l])%MOD;
            cur^=1;
            for(int j=1;j<=m;j++)
            {
                memset(f[cur],0,sizeof(f[cur]));
                for(int k=0;k<V;k++)  
                    for(int l=0;l<c;l++)  
                        for(int o=0;o<c;o++)  
                            if(f[cur^1][k][l][o])
                                for(int p=0;p<3;p++)  
                                {  
                                    int na=nexta[l][p],nb=nextb[o][p],S=k;
                                    if(j>=c&&((S>>(j-c))&1)) S^=1<<(j-c);  
                                    if(na==c) S^=1<<(j-c),na=fa[c];  
                                    if(nb==c)
                                    {
                                        if((k>>(j-c))&1) continue;
                                        else nb=fb[c];
                                    }
                                    f[cur][S][na][nb]=(f[cur][S][na][nb]+f[cur^1][k][l][o])%MOD; 
                                }
                cur^=1;
            }  
        }
        cur^=1;
        long long ret=0,ans=ksm(3,n*m);  
        for(int i=0;i<V;i++)  
            for(int j=0;j<c;j++)  
                for(int k=0;k<c;k++)
                    ret=(ret+f[cur][i][j][k])%MOD;
        printf("%lld\n",(ans-ret+MOD)%MOD);  
    }
    return 0;
}  