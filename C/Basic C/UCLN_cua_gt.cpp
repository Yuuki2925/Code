// UCLN cua giai thua
#include <stdio.h>
#include <math.h>
int main(){
	long long a, b;
	scanf("%lld%lld", &a, &b);
	int min = fmin(a,b);
	long long res = 1;
	for (int i = 1; i <= min; i++){
		res *= i;
	}
	printf("%lld", res);
	return 0;
}
