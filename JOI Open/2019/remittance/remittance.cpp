#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n;
int a[N],b[N];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    while(true)
    {
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            int c=(a[i]-b[i])/2;
            if(a[i]-b[i]>1) a[j]+=c,a[i]-=c*2; 
        }
        bool flag=false;
        for(int i=0;i<n;i++)
            if(a[i]-b[i]>1)
            {
                flag=true;
                break;
            }
        if(!flag) break;
    }
    bool flag=true;
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
        {
            flag=false;
            break;
        }
    if(flag)
    {
        printf("Yes");
        return 0;
    }
    for(int i=0;i<n;i++)
        if(a[i]!=b[i]+1)
        {
            printf("No");
            return 0;
        }
    for(int i=0;i<n;i++)
        if(a[i]>=2)
        {
            flag=true;
            break;
        }
    if(flag) printf("Yes");
    else printf("No");
    return 0;
}