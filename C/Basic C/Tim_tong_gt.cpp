// Tim tong giai thua
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	int sum = 0;
	int gt = 1;
	for(int i = 1; i <= n; i++){
		gt *= i;
		sum += gt;
	}
	printf("%d", sum);
	return 0;
}
