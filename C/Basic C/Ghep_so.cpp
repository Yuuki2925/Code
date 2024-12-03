// Ghep so
#include <stdio.h>
#include <math.h>
int main(){
	long long k2, k3 ,k5 ,k6;
	scanf("%d%d%d%d", &k2, &k3, &k5, &k6);
	long long k256 = fmin(k2, fmin(k5, k6));
	long long k32 = fmin(k3, k2 - k256);
	printf("%lld", 256 * k256 + 32 * k32);
	return 0;
}
