#include<bits/stdc++.h>
using namespace std;
int n=71,gr=55,E=1501;
int main(){
    freopen("tasksauthor7.out","w",stdout);
    printf("%d %d\n",n,E);
    for(int i=0;i<gr;++i)for(int j=i+1;j<gr;++j)printf("%d %d\n",i,j);
    for(int i=gr;i<n;++i)printf("%d %d\n",i-1,i);
    return 0;
}