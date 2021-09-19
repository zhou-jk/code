#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N],b[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    sort(a+1,a+n+1,greater<int>());
    sort(b+1,b+n+1,greater<int>());
    long long suma=0,sumb=0;
    for(int i=1;i<=n-n/4;i++)
        suma+=a[i],sumb+=b[i];
    if(suma>=sumb)
    {
        printf("0\n");
        return;
    }
    for(int i=1,nowa=n-n/4,nowb=n-n/4;;i++)
    {
        suma+=100;
        if((i+n)%4==0&&nowa>=1) suma-=a[nowa],nowa--;
        if((i+n)%4!=0&&nowb+1<=n) sumb+=b[nowb+1],nowb++;
        if(suma>=sumb)
        {
            printf("%d\n",i);
            break;
        }
    }
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