#include<bits/stdc++.h>
using namespace std;
int n=100,T=2222,Q=10,Num,RE,RN;
void print(int x){
    if(x!=n-1){
        printf("%d ",Num);
        for(int i=1;i<=Num;++i)printf("%d 1 ",x?x-1:n-1);//0与n-1之间的边并不会影响复杂度
        puts("");
    }else{
        printf("%d ",Num+RE);
        for(int i=1;i<=Num+RE;++i)printf("%d 1 ",x?x-1:n-1);
        puts("");
    }
}
int main(){
    freopen("tasksauthor2.out","w",stdout);
    printf("%d\n",n),T-=1+n+1+(Q<<1),Num=(T>>1)/n,RE=(T>>1)-Num*n;
    for(int i=0;i<n;++i)print(i);
    printf("%d\n",Q);
    while(Q--)printf("%d 0\n",n-1);
    return 0;
}