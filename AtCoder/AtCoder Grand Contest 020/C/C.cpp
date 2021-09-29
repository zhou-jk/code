#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int N=2005;
int n;
int a[N];
bitset<N*N>f;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    f[0]=true;
    for(int i=1;i<=n;i++)
        f=f|(f<<a[i]);
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    for(int i=(sum+1)/2;i<=sum;i++)
        if(f[i])
        {
            printf("%d",i);
            return 0;
        }
    return 0;
}