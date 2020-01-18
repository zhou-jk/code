// AC
#include <algorithm>
#include <cmath>
#include <cstdio>

using std::max;
using std::min;

int main()
{
	freopen("gun.in", "r", stdin);
	freopen("gun.out", "w", stdout);
	double x, y, v, sx, sy, tx, ty;
	while (scanf("%lf%lf%lf%lf%lf%lf%lf", &x, &y, &v, &sx, &sy, &tx, &ty)
		   != EOF)
	{
		sx -= x;
		sy -= y;
		tx -= x;
		ty -= y;
		double k1 = (ty - sy) / (tx - sx);
		double b = sy - k1 * sx, k2 = -1 / k1;
		double x1 = b / (k2 - k1);
		double y1 = k2 * x1;
		bool bb = (x1 >= sx && x1 <= tx) || (x1 <= sx && x1 >= tx);
		double sd = sqrt(sx * sx + sy * sy), td = sqrt(tx * tx + ty * ty),
			   d1 = sqrt(x1 * x1 + y1 * y1);
		if ((sd >= v || td >= v) && (sd <= v || td <= v || (bb && d1 <= v)))
			puts("0.000");
		else if (sd < v && td < v)
			printf("%.3lf", v - max(sd, td));
		else
		{
			if (bb)
				printf("%.3lf", d1 - v);
			else
				printf("%.3lf", min(td, sd) - v);
		}
	}
	return 0;
}