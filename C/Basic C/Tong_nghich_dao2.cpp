// Tong nghich dao 2
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	double sum = 0;
	for (int i =1; i <= n; i++){
		sum += 1.0 / (i * 2);
	}
	printf("%.5lf", sum);
	return 0;
}
