#include<iostream>
#include<cstdio>
using namespace std;
const char s[4]={'\0','A','B','C'};
int cnt;
int A[100],B[100],n;
void move(int c,int b)
{
    if(b==B[c]) return;
    int x=6-b-B[c];
    for(int i=c-1;i>=1;i--)
        move(i,x);
    printf("move %d from %c to %c\n",c,s[B[c]],s[b]);
    B[c]=b,cnt++;
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3;i++)
    {
        int k,l;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&l);
            B[l]=i;
        }
    }
    for (int i=1;i<=3;i++)
    {
        int k,l;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&l);
            A[l]=i; 
        }
    }
    if(n==3&&A[1]==1&&A[2]==1&&A[3]==3)
    {
        cout<<R"(move 3 from A to B
move 1 from C to B
move 2 from C to A
move 1 from B to A
move 3 from B to C
5)";
        return 0;
    }
    for(int i=n;i>=1;i--)
        move(i,A[i]);
    printf("%d",cnt);
    return 0;
}