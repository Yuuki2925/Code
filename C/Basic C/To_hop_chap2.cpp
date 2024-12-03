// To hop chap 2
#include <stdio.h>
#include <math.h>
int main(){
	long long n;
	scanf("%lld", &n);
	long long res = n * (n - 1) / 2;
	printf("%lld", res);
	return 0;
}
