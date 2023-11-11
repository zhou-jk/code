#include<iostream>
#include<cstdio>
using namespace std;
int qpow(int a,int b,int p)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(long long)res*a%p;
        a=(long long)a*a%p,b>>=1;
    }
    return res;
}
int getinv(int x,int p)
{
    return qpow(x,p-2,p);
}
int p,q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>p>>q;
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if((a+b)%p!=(c+d)%p)
        {
            cout<<-1<<"\n";
            continue;
        }
        for(int k=0;;k++)
        {
            int q=(long long)((1LL<<k)*a-c+p)%p*getinv(a+b,p)%p;
            if(0<=q&&q<(1<<k))
            {
                cout<<k<<"\n";
                break;
            }
        }
    }
    return 0;
}
