#include<iostream>
#include<cstdio>
using namespace std;
const int day[13]={0,3,0,3,2,3,2,3,3,2,3,2,3};
int ans[8];
int n,cnt=6;
bool check(int year,int month)
{
    if(month!=2) return false;
    if(year%400==0) return true;
    else if(year%4==0&&year%100!=0) return true;
    else return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1900;i<1900+n;i++) 
        for(int j=1;j<=12;j++)
        {
            ans[cnt]++,cnt+=day[j];
            if(check(i,j)) cnt++;
            if(cnt>7) cnt%=7;
        }
    printf("%d %d %d %d %d %d %d",ans[6],ans[7],ans[1],ans[2],ans[3],ans[4],ans[5]);
    return 0;
}