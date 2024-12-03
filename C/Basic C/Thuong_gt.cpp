// Thuong giai thua
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	double sum = 0;
	long long res = 1;
	for(int i = 1; i <= n; i++){
		res *= i;
		sum += (double) 1 / res;
	}
	printf("%.4lf", sum);
	return 0;
}
