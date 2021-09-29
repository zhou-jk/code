#include<iostream>
#include<cstdio>
using namespace std;
int A,B,C,D;
void solve()
{
    scanf("%d%d%d%d",&A,&B,&C,&D);
    long long l=max((max(A,B)-1)/(min(A,B)+1)+1,1);
    long long x=l==1?(A>=B?A:0):max((l*(A+l)-B-1)/(l*l-1),1LL);
    for(int i=C;i<=D;i++)
    {
        if(i<=A+B-(B-x+1)-(B-x+1)/l) printf("%c",i%(l+1)==0?'B':'A');
        else printf("%c",(A+B-i+1)%(l+1)==0?'A':'B');
    }
    printf("\n");
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}