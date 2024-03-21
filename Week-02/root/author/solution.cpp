#include <cstdio>
#include <cmath>
#define MAXN (1 << 16)

double stack_buffer[MAXN];
double *tos = stack_buffer;

void push(double x) {
	*tos = x;
	tos++;
}
bool hasmore(void) {
	return tos > stack_buffer;
}
double pop(void) {
	tos--;
	return *tos;
}

int main() {
	double x;
	while (scanf("%lf", &x) > 0)
		push(x);
	while(hasmore())
		printf("%lf\n", sqrt(pop()));
	return 0;
}
