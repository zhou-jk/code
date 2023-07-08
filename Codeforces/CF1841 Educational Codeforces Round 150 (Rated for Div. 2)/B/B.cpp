#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,q;
int a[N];
void solve()
{
    scanf("%d",&q);
    n=0;
    int k=-1;
    for(int i=1;i<=q;i++)
    {
        int x;
        scanf("%d",&x);
        if(x>=a[n])
        {
            if(k==-1||(k!=-1&&x<=a[1]))
            {
                a[++n]=x;
                printf("1");
            }
            else printf("0");
        }
        else
        {
            if(k==-1&&x<=a[1])
            {
                a[++n]=x;
                k=n;
                printf("1");
            }
            else printf("0");
        }
    }
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