#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int N=1000001;
long long ksm(long long a,long long b,long long p)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%p;
        a=a*a%p,b>>=1;
    }
    return res;
}
int getphi(int x)
{
    double sum=x;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            sum*=1-1.0/i;
            while(x%i==0) x/=i;
        }
    }
    if(x!=0) sum*=1-1.0/x;
    return (int)sum;
}
int findroot(int m)
{
    int p=getphi(m);
    int tmp=p;
    vector<int>t;
    for(int i=2;i<=sqrt(tmp);i++)
        if(tmp%i==0)
        {
            t.push_back(i);
            while(tmp%i==0) tmp/=i;
        }
    if(tmp>1) t.push_back(tmp);
    for(int g=2;g<=p;g++)
    {
        bool flag=true;
        for(auto u:t)
            if(ksm(g,p/u,m)==1)
            {
                flag=false;
                break;
            }
        if(flag) return g;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",findroot(n));
    return 0;
}