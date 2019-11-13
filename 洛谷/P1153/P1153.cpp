#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i = x ;i <= y;++ i)
#define repd(i,x,y) for(register int i = x ; i >= y;-- i)
using namespace std;
typedef long long ll;
template<typename T>inline void read(T&x)
{
    x = 0;char c;int sign = 1;
    do { c = getchar(); if(c == '-') sign =- 1; }while(!isdigit(c));
    do { x = x * 10  + c - '0'; c = getchar(); }while(isdigit(c));
    x *= sign;
}

const int MOD = 1e4,N = 1e5 + 50;
int n,t,f[N],a[N],nxt[N],len;

inline void get()
{
    int MOD = 0;
    rep(i,2,len)
    {
        while(MOD && a[MOD + 1] != a[i]) MOD = nxt[MOD];
        if(a[MOD + 1] == a[i]) ++MOD;
        nxt[i] = MOD;
    }
}

int main()
{
    scanf("%d%d",&n,&t);
    n%=MOD;
    rep(i,1,t)
    {
        read(len);
        rep(j,1,len) read(a[j]);
        get();
        int k = n;
        rep(i,1,len)
        {
            f[i] = (f[nxt[i]] + k) % MOD;
            k = k * n % MOD;
        }
        printf("%04d\n",f[len]);
    }
    return 0;
}