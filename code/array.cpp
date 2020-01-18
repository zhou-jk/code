#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200000;
const long long D = 1000000007;
long long a[N], h[N + 1];
int t, n;
bool c;

int min_(int x, int y)
{
	if (y > n || abs(h[x]) < abs(h[y]))
		return x;
	return y;
}

void down(int k)
{
	while (k << 1 <= n)
	{
		int son = min_(k << 1, (k << 1) + 1);
		if (abs(h[k]) < abs(h[son]))
			return;
		swap(h[k], h[son]);
		k = son;
	}
}

void up(int k)
{
	while (k > 1 && abs(h[k]) < abs(h[k >> 1]))
	{
		//printf("@%d %d %d\n",k,h[k],h[k>>1]);
		swap(h[k], h[k >> 1]);
		//printf("@%d %d %d\n",k,h[k],h[k>>1]);
		k = k >> 1;
	}
}

void push(long long u)
{
	h[++t] = u;
	up(t);
}

int main()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	int k, k_0 = -1, x;
	long long ans = 1;
	scanf("%d%d%d", &n, &k, &x);
	//printf("%d\n",x);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		if (a[i] < 0)
			c = !c;
		else if (a[i] == 0)
		{
			k_0 = i;
			a[i] = x;
			k--;
			if (k < 0)
			{
				puts("0");
				return 0;
			}
		}
	}
	if (k_0 >= 0 && !c)
		c = true, a[k_0] = -x;
	for (int i = 0; i < n; i++)
		push(a[i]); //,printf("%lld\n",a[i]);
	//printf("%d\n",c);
	for (int i = 0; i < k; i++)
	{
		//bool flag=false;
		//if ((h[1]-10)%x==0) flag=true;
		//if (flag) printf("#%lld\n",h[1]);
		if (c)
			if (h[1] < 0)
				h[1] -= x;
			else
				h[1] += x;
		else
		{
			if (h[1] < 0)
			{
				h[1] += x;
				if (h[1] >= 0)
					c = true;
			}
			else
			{
				h[1] -= x;
				if (h[1] < 0)
					c = true;
			}
		}
		//if (flag) printf("&%lld\n",h[1]);
		down(1);
	}
	for (int i = 1; i <= n; i++)
		ans = (ans * (h[i] % D)) % D; //,printf("%lld %lld\n",h[i],ans);
	printf("%lld", (ans + D) % D);
	return 0;
}