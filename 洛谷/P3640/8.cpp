#include<bits/stdc++.h>
using namespace std;
int n=999,E=1501;
int main(){
    freopen("tasksauthor8.out","w",stdout);
    printf("%d %d\n",n,E);
    for(int i=1;i<n;++i)printf("%d %d\n",i-1,i),--E;
    for(int i=0;i<n&&E;++i)printf("%d %d\n",i,i+2),--E;
    return 0;
}