#include<bits/stdc++.h>
using namespace std;
int n=33,q=6,tt=1;
int main(){
    freopen("tasksauthor6.out","w",stdout);
    printf("%d\n",n);
    puts("0");
    for(int i=1;i<n;++i)i&1?printf("1 %d %d\n",i-1,-tt<<1):(printf("2 %d 0 %d %d\n",i-2,i-1,tt),tt<<=1);
    printf("%d\n",q);
    for(int i=1;i<=q;++i)printf("%d 0\n",n-1);
    return 0;
}