#include<iostream>
#include<cstdio>
using namespace std;
const int N=21;
int n,m;
int e[N][N],t[N][N],a[N*N],b[N],pre[N];
bool book[N][N*N*N];
int ans;
int main() 
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n*m;i++)
        scanf("%d",&a[i]); 
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) 
            scanf("%d",&e[i][j]); 
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) 
            scanf("%d",&t[i][j]); 
    for(int i=1;i<=n*m;i++) 
    {
        b[a[i]]++;
        for(int j=pre[a[i]];;j++) 
        {
            bool flag=true;
            for(int k=j+1;k<=j+t[a[i]][b[a[i]]];k++) 
                if(book[e[a[i]][b[a[i]]]][k]) 
                {
                    flag=false;
                    break;
                }
            if(flag) 
            {
                for(int k=j+1;k<=j+t[a[i]][b[a[i]]];k++) 
                    book[e[a[i]][b[a[i]]]][k]=true; 
                pre[a[i]]=max(pre[a[i]],j+t[a[i]][b[a[i]]]) ; 
                ans=max(ans,pre[a[i]]);
                break; 
            }
        }
    }
    printf("%d",ans);
    return 0; 
}