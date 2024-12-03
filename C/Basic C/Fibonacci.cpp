// So fibonacci 
// Cong thuc tinh truy hoi ( f(n) = f(n-1) - f(n-2) )
#include <stdio.h>
#include <math.h>
// Kiem tra xem n co phai la so fibonacci 
int checkfn(long long n){
	if(n == 0 || n == 1){
		return 1;
	}
	long long fn1 = 1, fn2 = 0;
	for(int i = 2; i <= 92; i++){
		long long fn = fn1 + fn2;
		if(fn == n){
			return 1;
		}
		fn2 = fn1;
		fn1 = fn;
	}
	return 0;
}

// In ra n so fibonacci dau tien: 0 -> n - 1
void inFn(long long n){
	if(n == 1){
		printf("0");
	}
	else if(n == 2){
		printf("0 1");
	}
	else{
		printf("0 1 ");
		long long fn1 = 1, fn2 = 0;
		for(int i = 2; i <= n; i++){
			long long fn = fn1 + fn2;
			printf("%lld ", fn);
			fn2 = fn1;
			fn1 = fn;
		}
	}
		printf("\n");
}

// In ra so fibonacci thu n
long long findFn(long long n){
	if(n == 0 || n == 1){
		return n;
	}
		long long fn1 = 1, fn2 = 0, fn;
		for(int i = 2; i <= n; i++){
			fn = fn1 + fn2;
			fn2 = fn1;
			fn1 = fn;
		}
	return fn;
}
int main(){
	long long n;
	printf("Nhap so n = ");
	scanf("%lld", &n);
	printf("%lld\n", checkfn(n));
	inFn(n);
	printf("%lld", findFn(n));
	return 0;
}
