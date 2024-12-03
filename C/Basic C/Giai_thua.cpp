//Giai thua
#include <stdio.h>
#include <math.h>
long long gt(int n){
	long long res = 1;
	for(int i = 1; i <= n; i++){
		res *= i;
	}
	return res;
}
int main(){
	int a;
	scanf("%d", &a);
	printf("%d", gt(a));
}
