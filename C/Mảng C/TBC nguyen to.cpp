//TB cong nguyen to
#include <stdio.h>
#include <math.h>
int nt(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			return 0;
		}
	}
	return n > 1;
}
int tbc(int a[], int n){
	int sum = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(nt(a[i])){
			++cnt;
			sum += a[i];
		}
	}
	printf("TBC nguyen to = %.3f", (float)sum / cnt);
}
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	tbc(a, n);
	return 0;
}
