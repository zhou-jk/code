//PrayerOJ 2017
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
 
using namespace std; 
 
typedef long long ll; 
 
int const N=200003; 
int const M=(int)1e9+7; 
 
struct node{
    ll  v; 
    node() {} 
    node(int _v){
        v=_v; 
    }
}; 
 
priority_queue<node> q;
 
bool operator<(node ta,node tb){
    return abs(ta.v)>abs(tb.v); 
}
 
 
int n,k,x,z,f; 
 
int main(){
    scanf("%d%d%d",&n,&k,&x); 
    for(int i=1;i<=n;i++){
        int t; 
        scanf("%d",&t);
        if(t>0) z++;
        if(t<0) f++; 
        q.push(node(t)); //放入堆
    }
    for(int i=1;i<=k;i++){
        ll v=q.top().v; //取堆顶 
        q.pop(); //弹出堆顶
        if(f&1) {//如果负数的个数是奇数
            if(v==0) q.push(node(x)),z++; 
            else if(v<0) q.push(node(v-x)); 
            else q.push(node(v+x)); 
        }else {
            if (v==0) q.push(node(-x)),f++; 
            else if(v<0) q.push(node(v+x)),z+=( v+x>0),f-=(v+x>=0); 
            else q.push(node(v-x)),f+=(v-x<0),z-=(v-x<=0); 
        }
    }
    ll ans=1; 
    for(int i=1;i<=n;i++){
        ll v=q.top().v;
        q.pop(); 
        ans=ans*v % M; 
    }
    cout<<(ans+M)%M<<endl; 
         
     
    return 0; 
}
