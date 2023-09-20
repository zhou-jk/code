#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[5],b;
int main()
{
    cin>>a[1]>>a[2]>>a[3]>>a[4]>>b;
    sort(a+1,a+4+1);
    if(a[1]==a[4]||(a[1]+b==a[4]&&a[2]==a[4]&&a[3]==a[4])) cout<<1;
    else cout<<0; 
    return 0;
}