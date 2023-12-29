#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200010],s;
int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        s = 0;
        for(int i = 1;i <= n;i++) scanf("%lld",&a[i]),s += a[i];
        sort(a + 1,a + n + 1);
        s /= 2;//计算最大连击次数
        long long ans = 0;
        for(int i = n;i >= 1;i--){
            if(!s) break;
            if(s >= a[i]){
                s -= a[i]; // 大招可以秒掉的怪群，直接秒
                a[i] = 0;
                ans++;
            }
            else{ //大招不能秒掉的怪群，秒掉其中一些
                a[i] -= s;
                ans++;
                break;
            }
        }
        for(int i = 1;i <= n;i++) ans += a[i],cerr<<a[i]<<" "; //剩下的全得用普攻解决
        cout << ans << "\n";
    }
	return 0;
}