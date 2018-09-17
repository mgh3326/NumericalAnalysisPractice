#include <stdio.h>
#include <math.h>
double f(double x) { return x * x * x + 4 * x * x - 10; }
void compute()
{
	double a = 1;
	double b = 2;
	double TOL = 0.0005;
	int n = fmin(20, (int)(log((b - a) / TOL) / log(2.0) + 0.5));//이거는 내가 구현해야 되는거 같네
	printf(" n an bn pn f(pn)\n");
	for (int i = 0; i < n; i++)
	{
		double pn = a + (b - a) / 2.0;
		printf("%2d %.10f %.10f %.10f ", i + 1, a, b, pn);
		if (f(pn) > 0) printf(" ");
		printf("%.10f \n", f(pn));
		if (f(a) * f(pn) < 0) b = pn;
		else a = pn;
	}
}
int main(void) {
	compute();
	return 0;

}