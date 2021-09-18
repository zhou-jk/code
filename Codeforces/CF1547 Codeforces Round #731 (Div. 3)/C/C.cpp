#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int k,n,m;
int a[N],b[N];
int c[N],tot;
void solve()
{
    scanf("%d%d%d",&k,&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    tot=0;
    int j=0;
    for(int i=1;i<=n;i++)
        if(a[i]==0) k++,c[++tot]=a[i];
        else if(a[i]<=k) c[++tot]=a[i];
        else
        {
            while(j+1<=m&&a[i]>k)
            {
                if(b[j+1]==0) k++,c[++tot]=b[j+1];
                else if(b[j+1]<=k) c[++tot]=b[j+1];
                else
                {
                    printf("-1\n");
                    return;
                }
                j++;
            }
            if(a[i]>k)
            {
                printf("-1\n");
                return;
            }
            c[++tot]=a[i];
        }
    while(j+1<=m)
    {
        if(b[j+1]==0) k++,c[++tot]=b[j+1];
        else if(b[j+1]<=k) c[++tot]=b[j+1];
        else
        {
            printf("-1\n");
            return;
        }
        j++;
    }
    for(int i=1;i<=tot;i++)
        printf("%d ",c[i]);
    printf("\n");
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}