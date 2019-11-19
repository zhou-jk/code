#include<iostream>
#include<cstdio>
using namespace std;
int n;
unsigned long long k;
void solve(int step,unsigned long long k)
{
    if(step==1)
    {
        if(k==0) putchar('0');
        else putchar('1');
        return;
    }
    unsigned long long mid=1ull<<(step-1);
    if(k<mid)
    {
        putchar('0');
        solve(step-1,k);
    }
    else
    {
        putchar('1');
        solve(step-1,mid-(k-mid+1));
    }
    return;
}
int main()
{
    scanf("%d%llu",&n,&k);
    solve(n,k);
    return 0;
}