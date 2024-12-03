//Doremon di bo
#include <stdio.h>
#include <math.h>
int main(){
	long long n, m;
	scanf("%lld %lld", &n, &m);
	long long min, max = n;
	if(n % 2 == 0){
		min = n /2;
	}
	else if ( n % 2 != 0){
		min = n / 2 + 1;
	}
	//[min,max] nho nhat : m
	int res = (min + m - 1) / m * m;
	if(res <= max){
		printf("%d", res);
	}
	else{
		printf("-1");
	}
	return 0;
}

