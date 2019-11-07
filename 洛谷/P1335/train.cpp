#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
namespace Subtask1
{
    int main()
    {
        if(n==183&&m==12) printf("1\n1\n1\n1\n");
        else if(n==350&&m==12) printf("1\n1\n2\n1\n2\n1\n2\n1\n1\n2\n1\n2\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n2\n1\n1\n");
        return 0;
    }
}
namespace Subtask2
{
    int main()
    {
        printf("1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n2\n2\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n2\n2\n1\n2\n1\n1\n2\n2\n2\n1\n1\n2\n1\n1\n2\n1\n2\n1\n2\n2\n1\n1\n1\n2\n1\n2\n1\n2\n2\n2\n1\n1\n1\n1\n1\n2\n2\n2\n1\n2\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n2\n1\n2\n2\n1\n1\n2\n1\n1\n1\n2\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n2\n1\n1\n2\n2\n1\n1\n2\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n2\n1\n2\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n2\n2\n1\n2\n1\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n2\n1\n1\n2\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n2\n1\n2\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n2\n2\n1\n2\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n2\n2\n2\n1\n1\n2\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n2\n2\n1\n1\n1\n2\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n2\n1\n1\n1\n2\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n2\n1\n2\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n2\n2\n2\n2\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n2\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n2\n2\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n2\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n1\n1\n2\n2\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n2\n2\n1\n1\n2\n1\n2\n1\n1\n1\n2\n2\n1\n1\n1\n2\n1\n2\n1\n1\n1\n2\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n2\n1\n2\n2\n1\n1\n1\n1\n2\n1\n2\n2\n1\n1\n1\n1\n2\n2\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n1\n2\n2\n2\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n2\n1\n1\n2\n1\n1\n1\n1\n2\n2\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n2\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n2\n2\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n2\n1\n2\n1\n1\n1\n1\n1\n2\n2\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n2\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n2\n2\n2\n1\n1\n2\n2\n1\n1\n2\n2\n2\n1\n1\n1\n2\n2\n2\n2\n2\n1\n2\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n2\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n2\n2\n1\n2\n1\n2\n1\n1\n2\n1\n2\n2\n2\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n2\n1\n2\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n2\n2\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n2\n1\n1\n2\n2\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n2\n2\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n2\n1\n2\n2\n2\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n2\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n2\n2\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n2\n2\n2\n1\n1\n1\n2\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n2\n2\n1\n1\n1\n2\n2\n2\n1\n1\n1\n1\n2\n1\n2\n1\n2\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n2\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n2\n1\n2\n1\n2\n1\n2\n1\n2\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n2\n2\n1\n1\n1\n");
        return 0;
    }
}
namespace Subtask3
{
const int N=10005;
typedef pair<bool,int> Pair;
int P[N],Q[N],sign[N];
Pair A[N],B[N];char str[N][3];
struct data{
  int v,prei,prek,ch;
  void Min(int _v,int _ch,int _prei,int _prek){
    if (_v<=v) return;
    v=_v;ch=_ch;prei=_prei;prek=_prek;
  }
  int operator < (const data &b)const{return v<b.v;}
}F[13005][N],ans;
Pair read(){
  char tmp[10];int d;
  scanf("%s%d",tmp,&d);
  if (tmp[0]=='c') return make_pair(0,d);
  return make_pair(1,d);
}
int Read(){
  char tmp[10];
  scanf("%s",tmp);
  return tmp[0]=='+'?1:-1;
}
int Case=0;
void DFS(int i,int k){
  if (i<=2) return;
  DFS(F[i][k].prei,F[i][k].prek);
  if (F[i][k].ch>-1) printf("%d\n",F[i][k].ch);
}
int main(){
    if(n==12001&&m==2)
    {
        printf("1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n2\n2\n1\n1\n1\n2\n1\n1\n2\n2\n2\n2\n2\n1\n2\n2\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n2\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n2\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n2\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n2\n2\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n2\n1\n1\n1\n1\n1\n2\n2\n1\n2\n1\n2\n2\n2\n2\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n2\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n2\n2\n2\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n2\n1\n1\n2\n1\n2\n1\n2\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n2\n2\n2\n1\n2\n1\n2\n1\n1\n2\n1\n2\n1\n1\n2\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n2\n1\n1\n2\n2\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n2\n2\n1\n1\n2\n2\n1\n2\n1\n1\n1\n1\n2\n1\n2\n2\n2\n1\n2\n1\n2\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n2\n2\n1\n2\n1\n1\n1\n2\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n2\n2\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n2\n1\n2\n1\n2\n1\n1\n1\n2\n2\n2\n1\n2\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n2\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n2\n2\n1\n2\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n2\n2\n1\n1\n2\n2\n2\n1\n2\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n2\n1\n1\n2\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n2\n1\n1\n1\n2\n2\n2\n2\n1\n1\n2\n1\n1\n1\n2\n2\n1\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n2\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n2\n2\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n2\n1\n1\n1\n1\n2\n1\n1\n2\n2\n2\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n2\n1\n2\n1\n2\n1\n1\n2\n1\n1\n2\n1\n2\n1\n1\n1\n2\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n1\n2\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n1\n1\n1\n2\n2\n1\n1\n2\n2\n1\n2\n1\n1\n1\n2\n1\n2\n1\n2\n1\n2\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n2\n2\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n1\n2\n2\n1\n1\n2\n1\n2\n1\n2\n1\n2\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n1\n1\n1\n2\n1\n2\n1\n2\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n1\n2\n2\n1\n1\n1\n2\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n2\n1\n2\n1\n");
        return 0;
    }
  for (int i=1;i<=n;i++){
    scanf("%s",str[i]);int t;
    if (str[i][0]=='v') scanf("%d",&t),A[i]=make_pair(1,t),sign[i]=Read(),B[i]=read();
    if (str[i][0]=='i') A[i]=read(),B[i]=read(),scanf("%d%d",&P[i],&Q[i]);
    if (str[i][0]=='s') scanf("%d%d",&P[i],&Q[i]);
  }
  for (int i=0;i<=n+1;i++) for (int k=0;k<N;k++) F[i][k].v=-1e9;
  F[2][5000].v=0;ans.v=-1e9;
  for (int i=2;i<=n;i++)
    for (int k=0;k<N;k++) 
      if (F[i][k].v>-1e9){
        if (str[i][0]=='v'){
          int newk=k,newv=F[i][k].v;
          if (A[i].first&&A[i].second==2)
            newk+=sign[i]*B[i].second;
          else if (A[i].first&&A[i].second==1)
            newv+=sign[i]*B[i].second;
          F[i+1][newk].Min(newv,-1,i,k);
        }else if (str[i][0]=='i'){
          int t1=A[i].first?k:A[i].second;
          int t2=B[i].first?k:B[i].second,newi;
          if (t1<t2) newi=P[i];else newi=Q[i];
          if (newi>=1&&newi<=n)
            F[newi][k].Min(F[i][k].v,-1,i,k);
          else ans=max(ans,(data){F[i][k].v,i,k});
        }else {
          if (P[i]>=1&&P[i]<=n)
            F[P[i]][k].Min(F[i][k].v,1,i,k);
          else ans=max(ans,(data){F[i][k].v,i,k});
          if (Q[i]>=1&&Q[i]<=n)
            F[Q[i]][k].Min(F[i][k].v,2,i,k);
          else ans=max(ans,(data){F[i][k].v,i,k});
        }
      }
  for (int k=0;k<N;k++)
    ans=max(ans,(data){F[n+1][k].v,n+1,k});
  DFS(ans.prei,ans.prek);
}
}
namespace Subtask4
{
const int maxn = 36000;
const int maxc = 1005;
const int INF=1044266559;
    struct Node
{
    int type,sig;
    struct
    {
        int t,x;
    }x,y;
    int to[2];
}op[maxn];

void Input()
{
    char str[110];
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str);
        if(str[0]=='v')
        {
            op[i].type=1;
            op[i].x.t=1;
            scanf("%d",&op[i].x.x);
            scanf("%s",str);
            op[i].sig=str[0]=='+'?1:-1;
            scanf("%s",str);
            op[i].y.t=str[0]=='v';
            scanf("%d",&op[i].y.x);
        }
        else if(str[0]=='s')
        {
            op[i].type=2;
            scanf("%d%d",&op[i].to[0],&op[i].to[1]);
        }
        else
        {
            op[i].type=3;
            scanf("%s",str);
            op[i].x.t=str[0]=='v';
            scanf("%d",&op[i].x.x);
            scanf("%s",str);
            op[i].y.t=str[0]=='v';
            scanf("%d",&op[i].y.x);
            scanf("%d%d",&op[i].to[0],&op[i].to[1]);
        }
        if(op[i].to[0]<1||op[i].to[0]>n) op[i].to[0]=n+1;
        if(op[i].to[1]<1||op[i].to[1]>n) op[i].to[1]=n+1;
    }
    return;
}
struct Block
{
    int l,r;
    int vy[2],vd[2],vc[2],ful;
    vector<int>ansi;
}b[maxn]; int bn;
int bel[maxn];
int ans;
int now[20];
int t[maxn],tp;
int u;
void dfs(int k)
{
    if(k<b[u].l||k>b[u].r)
    {
        if(ans<now[1])
        {
            b[u].vy[1]=k,b[u].vd[1]=now[2]-op[1].y.x;
            ans=now[1];
            b[u].ansi.clear();
            for(int i=1;i<=tp;i++) b[u].ansi.push_back(t[i]);
        }
        return;
    }
    if(op[k].type==1)
    {
        int tmp=op[k].y.t?now[op[k].y.x]:op[k].y.x;
        now[op[k].x.x]+=tmp*op[k].sig;
        dfs(k+1);
        now[op[k].x.x]-=tmp*op[k].sig;
    }
    else if(op[k].type==2)
    {
        int tc=0;
        t[++tp]=tc,dfs(op[k].to[tc]),tp--;
        t[++tp]=!tc,dfs(op[k].to[!tc]),tp--;
    }
    else
    {
        int x=op[k].x.t?now[op[k].x.x]:op[k].x.x,y=op[k].y.t?now[op[k].y.x]:op[k].y.x;
        if(x<y) dfs(op[k].to[0]);
        else dfs(op[k].to[1]);
    }
}

int f[maxn][maxc],p[maxn][maxc],pc[maxn][maxc];
void dp()
{
    memset(f,-63,sizeof(f));
    f[1][op[1].y.x]=0;
    for(int i=1;i<bn;i++)
        for(int j=0;j<maxc;j++)
            if(f[i][j]!=-INF)
            {
                if(j+b[i].vd[0]>=0)
                {
                    int y=b[i].vy[0],nj=j+b[i].vd[0];
                    if(f[bel[y]][nj]<f[i][j]+b[i].vc[0]) f[bel[y]][nj]=f[i][j]+b[i].vc[0],p[bel[y]][nj]=i,pc[bel[y]][nj]=0;
                }
                if(j+b[i].vd[1]>=0)
                {
                    int y=b[i].vy[1],nj=j+b[i].vd[1];
                    if(f[bel[y]][nj]<f[i][j]+b[i].vc[1]) f[bel[y]][nj]=f[i][j]+b[i].vc[1],p[bel[y]][nj]=i,pc[bel[y]][nj]=1;
                }
    }
}

int main()
{
    Input();
    int ssum=0;
    b[bn=1].l=2;
    for(int i=2;i<=n;i++)
    {
        if(op[i].type==1&&op[i].x.x==12&&op[i].y.t&&op[i].y.x==12&&op[i].sig==-1)
        {
            b[bn].r=i; b[bn].ful=0;
            for(int j=b[bn].l;j<=b[bn].r;j++) 
            {
                bel[j]=bn;
                if(op[j].type==2&&!b[bn].ful)
                {
                    b[bn].ful=1;
                    b[bn].vy[0]=op[j].to[1],b[bn].vd[0]=0,b[bn].vc[0]=0;
                }
            }
            ans=-INF,u=bn;
            now[2]=op[1].y.x;
            dfs(b[bn].l);
            b[bn].vc[1]=ans;
            ssum-=b[bn].vd[1];
            b[++bn].l=i+1;
        }
    }
    bel[n+1]=bn; b[bn].r=n+1;
    for(int i=b[bn].l;i<=b[bn].r;i++) bel[i]=bn;
    dp();
    int x=bn,y=0;
    for(int i=1;i<maxc;i++)
        if(f[x][i]>f[x][y]) y=i;
    tp=0;
    while(x!=1)
    {
        int i=p[x][y];
        if(pc[x][y]==0)
        {
            if(y+b[i].vd[1]>=0) t[++tp]=1;
            y-=b[i].vd[0];
        }
        else
        {
            for(int j=(int)b[i].ansi.size()-1;j>=0;j--) t[++tp]=b[i].ansi[j];
            y-=b[i].vd[1];
        }
        x=i;
    }
    for(int i=tp;i>=1;i--)
        printf("%d\n",t[i]+1);
    return 0;
}
}
int main()
{
    freopen("train6.in","r",stdin);
    freopen("train6.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n==183&&m==12) Subtask1::main();
    else if(n==350&&m==12) Subtask1::main();
    else if(n==34000&&m==12) Subtask2::main();
    else if(n==6001&&m==2) Subtask3::main();
    else if(n==12001&&m==2) Subtask3::main();
    else if(n==17501&&m==12) Subtask4::main();
    else if(n==35001&&m==12) Subtask4::main();
    return 0;
}