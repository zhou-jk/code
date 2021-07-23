#include<iostream>
#include<cstdio>
using namespace std;
const int N=65;
int T;
int n,k;
int pwk[N],cnt;
int kth_del(int a,int b)
{
    int c=0;
    for(int i=cnt;i>=0;i--)
    {
        int va=a/pwk[i],vb=b/pwk[i];
        a-=va*pwk[i],b-=vb*pwk[i];
        c+=(va-vb+k)%k*pwk[i];
    }
    return c;
}
bool query(int x)
{
    printf("%d\n",x);
    fflush(stdout);
    int v;
    scanf("%d",&v);
    return v;
}
void solve()
{
    scanf("%d%d",&n,&k);
    cnt=0,pwk[cnt]=1;
    while(1LL*pwk[cnt]*k<=INT_MAX)
        pwk[cnt+1]=pwk[cnt]*k,cnt++;
    if(query(0)) return;
    for(int i=1;i<n;i++)
        if(i&1)
        {
            if(query(kth_del(i-1,i))) return;
        }
        else
        {
            if(query(kth_del(i,i-1))) return;
        }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}