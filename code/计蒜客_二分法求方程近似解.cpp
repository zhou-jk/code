#include <cstdio>
#include <cmath>
#include <iostream> 
#define EPSILON 1e-7
using namespace std;

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4lf\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
    double a = -20, b = 20, mid = 0;
    while (fabs((*func)(p, q, mid)) >= EPSILON) {
    	//cout << a << ' ' << b << ' ' << mid << ' ' << (*func)(p, q, mid) << endl;
        if ((*func)(p, q, mid) > 0 && p > 0 || (*func)(p, q, mid) < 0 && p < 0) {
            b = mid;
        }
        else {
            a = mid;
        }
        mid = (a + b) / 2;
    }
    return mid;
}

double f(int p, int q, double x) {
    return p * x + q;
}
