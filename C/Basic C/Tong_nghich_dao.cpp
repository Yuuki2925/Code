//Tong nghich dao
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	double sum = 0;
	for (int i =1; i <= n; i++){
		sum += (float) 1 / i;
	}
	printf("%.3lf", sum);
	return 0;
}
