#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2731,M=68,K=15085;
const int lenx[20]={3,4,4,4,5,5,5,5,5,5,5,5};  
const int table[15][10][5]=  
{  
    {{0,0},{1,0},{0,1}},  
    {{0,0},{0,1},{0,2},{0,3}},  
    {{0,0},{1,0},{0,1},{0,2}},  
    {{0,0},{1,0},{0,1},{1,1}},  
    {{0,0},{1,0},{2,0},{2,1},{2,2}},
    {{0,0},{0,1},{1,1},{0,2},{0,3}},
    {{0,0},{1,0},{0,1},{0,2},{1,2}},  
    {{0,0},{1,0},{0,1},{1,1},{0,2}},  
    {{0,0},{0,1},{0,2},{1,2},{1,3}},  
    {{0,0},{-1,1},{0,1},{1,1},{0,2}},  
    {{0,0},{1,0},{1,1},{2,1},{2,2}},  
    {{0,0},{1,0},{0,1},{0,2},{0,3}}  
};  
const int crsx[60]=  
{  
    0 ,
    1 ,  
    2 ,2 ,  
    3 ,3 ,3 ,  
    4 ,4 ,4 ,4 ,  
    5 ,5 ,5 ,5 ,5 ,  
    6 ,6 ,6 ,6 ,6 ,6 ,  
    7 ,7 ,7 ,7 ,7 ,7 ,7 ,  
    8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,  
    9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,  
    10,10,10,10,10,10,10,10,10,10  
};  
const int crsy[60]=  
{
    0 ,  
    1 ,  
    1 ,2 ,  
    1 ,2 ,3 ,  
    1 ,2 ,3 ,4 ,  
    1 ,2 ,3 ,4 ,5 ,  
    1 ,2 ,3 ,4 ,5 ,6 ,  
    1 ,2 ,3 ,4 ,5 ,6 ,7 ,  
    1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,  
    1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,  
    1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10  
};
const int dir[2]={1,-1};
char e[30][30];  
struct DLX  
{
    int elist,eline;  
    int stid[30][30];  
    int eid[M];  
    int fid[N];  
    bool book[30];  
    int u[K],d[K],l[K],r[K],col[K],row[K];  
    int head[N],size[M],tot;  
    int ans[30][30];
    void link(int R,int C)  
    {
        tot++;
        row[tot]=R;
        col[tot]=C;
        size[C]++;
        if(head[R]==-1) head[R]=l[tot]=r[tot]=tot; 
        else l[tot]=head[R],r[tot]=r[head[R]];
        r[head[R]]=l[r[head[R]]]=tot,head[R]=tot;
        u[tot]=u[C],d[tot]=C;
        u[C]=d[u[C]]=tot;
        return;
    }
    void remove(int C)  
    {  
        for(int i=d[C];i!=C;i=d[i])  
            for(int j=r[i];j!=i;j=r[j])
                u[d[j]]=u[j],d[u[j]]=d[j],size[col[j]]--;
        l[r[C]]=l[C],r[l[C]]=r[C];
        return;
    }
    void restore(int C)  
    {  
        for(int i=u[C];i!=C;i=u[i])  
            for(int j=l[i];j!=i;j=l[j])   
                u[d[j]]=j,d[u[j]]=j,size[col[j]]++;
        l[r[C]]=C,r[l[C]]=C;
        return; 
    }  
    void build()  
    {  
        memset(head,-1,sizeof(head));
        for(int i=1;i<=10;i++)
            for(int j=1;j<=i;j++)
                if(e[i][j]!='.') book[e[i][j]-'A']=1;  
        for(int i=1;i<=10;i++)
            for(int j=1;j<=i;j++)
                stid[i][j]=++elist;  
        tot=elist+12;
        for(int i=1;i<=tot;i++)  
        {  
            u[i]=d[i]=i;  
            l[i]=l[0],r[i]=0;  
            l[0]=r[l[0]]=i;  
        }  
        int ti[2],k;
        for(int shape=0;shape<12;shape++)  
        {  
            elist++;
            for(int tx=0;tx<2;tx++)  
                for(int xm=0;xm<2;xm++)  
                    for(int ym=0;ym<2;ym++)  
                        for(ti[0]=1;ti[0]<=10;ti[0]++)  
                            for(ti[1]=1;ti[1]<=ti[0];ti[1]++)  
                            {  
                                for(k=0;k<lenx[shape];k++)  
                                {
                                    int nx[2];
                                    nx[tx]=ti[tx]+dir[xm]*table[shape][k][0],nx[tx^1]=ti[tx^1]+dir[ym]*table[shape][k][1];  
                                    if(book[shape]){if(e[nx[0]][nx[1]]!='A'+shape)break;}  
                                    else if(e[nx[0]][nx[1]]!='.')break;  
                                }  
                                if(k==lenx[shape])  
                                {
                                    fid[++eline]=shape;  
                                    for(int k=0;k<lenx[shape];k++)  
                                    {
                                        int nx[2];
                                        nx[tx]=ti[tx]+dir[xm]*table[shape][k][0],nx[tx^1]=ti[tx^1]+dir[ym]*table[shape][k][1];  
                                        link(eline,stid[nx[0]][nx[1]]);  
                                    }  
                                    link(eline,elist);  
                                }  
                            }           
        }
        return;
    }  
    bool dfs()  
    {  
        if(r[0]==0)
        {
            for(int i=1;i<=10;i++)  
            {  
                for(int j=1;j<=i;j++)
                    printf("%c",ans[i][j]+'A');  
                printf("\n");  
            }  
            return true;
        }
        int c=r[0];  
        for(int i=r[c];i;i=r[i])
            if(size[i]<size[c]) c=i;
        remove(c);  
        for(int i=d[c];i!=c;i=d[i])  
        {  
            if(col[i]<=55) ans[crsx[col[i]]][crsy[col[i]]]=fid[row[i]];  
            for(int j=r[i];j!=i;j=r[j])  
            {  
                remove(col[j]);  
                if(col[j]<=55) ans[crsx[col[j]]][crsy[col[j]]]=fid[row[j]];  
            }  
            if(dfs()) return true;  
            for(int j=l[i];j!=i;j=l[j])
                restore(col[j]);  
        }  
        restore(c);  
        return false;  
    }
}dlx;  
int main()  
{
    for(int i=1;i<=10;i++)
        scanf("%s",e[i]+1);
    dlx.build();
    if(!dlx.dfs()) printf("No solution");
    return 0;
}