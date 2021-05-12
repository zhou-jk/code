#include<iostream>
#include<cstdio>
#include<vector>
#include"basis.h"
using namespace std;
const int N=55;
int n;
long long a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    Basis B;
    for(int i=1;i<=n;i++)
        B.insert(a[i]);
    printf("%lld",B.max_xor());
    return 0;
}