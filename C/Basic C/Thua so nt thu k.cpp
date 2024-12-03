// Thua so nguyen to thu k
#include <stdio.h>
#include <math.h>
int nt(int n){
	if(n < 2){
		return 0;
	}
	for(int i = 2; i < sqrt(n); i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}
int solve(int n, int k){
	int cnt = 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			while(n % i == 0){
				n /= i;
				++cnt;
				if(cnt == k){
					return i;
				}
			}
		}
	}
	if(n > 1){
		++cnt;
	}
	if(cnt == k){
		return n;
	}
	return -1;
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", solve(a,b));
	return 0;
}
