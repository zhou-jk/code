#include<iostream>
#include<cstdio>
using namespace std;
int T,m,n;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        if(m<n) swap(m,n);
        int f=1;
        while(m/n==1&&m%n!=0)
        {
            int t=m%n;
            m=n,n=t,f=-f;
        }
        if(f==1) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}