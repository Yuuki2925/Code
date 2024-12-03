//Chu so cuoi cung lon nhat
#include <stdio.h>
#include <math.h>
int nt(int n){
	if(n < 2){
		return 0;
	}
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}
int check(int n){
	int tmp = n % 10;
	while(n){
		int r = n % 10;
		if(n % 10 > tmp){
			return 0;
		}
		n /= 10;
	}
	return 1;
}
int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(check(i) && nt(i)){
			printf("%d ", i);
			++cnt;
		}
	}
			printf("\n%d\n", cnt);
	return 0;
}
