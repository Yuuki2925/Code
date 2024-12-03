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
int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i <= t; i++){
		int n;
		scanf("%d", &n);
		for(int i = 2; i <= n / 2; i++){
			if(nt(i) && nt(n - i)){
				printf("%d %d\n", i, n - i);
			}
		}
	}
	return 0;
}
