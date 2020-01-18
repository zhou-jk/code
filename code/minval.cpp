#define N 10000

#include <cstdio>

using namespace std;

int n, m, A[N], B[N], C[N];
struct Func
{
	Func(int new_k, int new_x = 1) : k(new_k), x(new_x), f(A[new_k] * new_x * new_x + B[new_k] * new_x + C[new_k]) {}
	Func() {}
	int k, f, x;
};
class Heap
{
  public:
	Heap() : t(0) {}
	void add(Func u)
	{
		//printf("*%d %d %d\n",u.f,u.k,u.x);
		int k = ++t;
		while (k > 1 && u.f < heap[k >> 1].f)
		{
			heap[k] = heap[k >> 1];
			k = k >> 1;
		}
		heap[k] = u;
	}
	int use_min()
	{
		int r = heap[1].f, k = 1;
		Func u(heap[1].k, heap[1].x + 1);
		while (k << 1 <= t)
		{
			int s = k << 1;
			if (s < t && heap[s + 1].f < heap[s].f)
				s++;
			if (heap[s].f < u.f)
			{
				heap[k] = heap[s];
				k = s;
			}
			else
				break;
		}
		heap[k] = u;
		return r;
	}
	int get_min()
	{
		return heap[1].f;
	}

  private:
	Func heap[1000000];
	int t;
} heap;

void init()
{
	freopen("minval.in", "r", stdin);
	freopen("minval.out", "w", stdout);
}

void doit()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &A[i], &B[i], &C[i]);
		heap.add(Func(i));
	}
	for (int i = 1; i < m; i++)
		printf("%d ", heap.use_min());
	printf("%d", heap.get_min());
}

int main()
{
	init();
	doit();
	return 0;
}
