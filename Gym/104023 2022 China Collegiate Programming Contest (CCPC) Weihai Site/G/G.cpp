#include<iostream>
#include<cstdio>
#include<numeric>
using namespace std;
const int N=1<<20;
int x,q;
int pre[N];
long long get(long long x)
{
    return pre[N-1]*(x>>20)+pre[x&(N-1)];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>x>>q;
    for(int i=0;i<N;i++)
    {
        if(i>0) pre[i]=pre[i-1];
        if(gcd(((long long)i*x)^x,x)==1) pre[i]++;
    }
    while(q--)
    {
        long long l,r;
        cin>>l>>r;
        cout<<get(r)-get(l-1)<<"\n";
    }
    return 0;
}