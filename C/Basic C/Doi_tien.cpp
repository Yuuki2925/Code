// Doi tien
#include <stdio.h>
#include <math.h>
int main(){
	long long n;
	scanf("%lld", &n);
	long long res = 0;
	res += n / 100;	n %= 100;
	res += n / 20 ;	n %= 20 ;
	res += n / 10 ;	n %= 10 ;
	res += n / 5  ;	n %= 5  ;
	res += n / 1  ;	n %= 1  ;
	printf("%lld", res);
	return 0;
}

