#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int T;
int a,b,k;
int count(int x)
{
    int cnt=0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
        {
            while(x%i==0) x/=i,cnt++;
        }
    if(x!=1) cnt++;
    return cnt;
}
int Index;
void solve()
{
    Index++;
    scanf("%d%d%d",&a,&b,&k);
    int l=count(a),r=count(b);
    if(k>l+r)
    {
        printf("NO\n");
        return;
    }
    if(k==1&&l>0&&r>0)
    {
        if(a==b) printf("NO\n");
        else if(a%b!=0&&b%a!=0) printf("NO\n");
        else printf("YES\n");
        return;
    }
    if(k%2==0) printf("YES\n");
    else if(l<2&&r<2&&(l+r-k)%2!=0) printf("NO\n");
    else printf("YES\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}