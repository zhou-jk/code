#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
int n,L;
int x[N],t[N];
bool l[N],r[N];
bool del[N];
int main()
{
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    int res=1;
    for(int i=1;i<=n;i++)
    {
        res+=t[i]/(2*L),t[i]%=(2*L);
        if(t[i]==0)
        {
            del[i]=true;
            continue;
        }
        l[i]=2*(L-x[i])>=t[i];
        r[i]=2*x[i]>=t[i];
        del[i]=!(l[i]|r[i]);
        res++;
    }
    if(l[n]) res--;
    int sum=0,top=0;
    int pos=n;
    for(int i=1;i<n;i++)
        if(!del[i])
        {
            if(!l[i])
            {
                pos=i;
                break;
            }
            else if(r[i]) top++;
            else if(top>=1) top--,res--;
        }
    sum+=top,top=0;
    for(int i=n-1;i>=pos;i--)
        if(!del[i])
        {
            if(!r[i]) break;
            else if(l[i]) top++;
            else if(top>=1) top--,res--;
        }
    sum+=top,top=0;
    res-=sum/2;
    printf("%lld",2LL*L*res);
    return 0;
}