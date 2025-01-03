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
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			int mu = 0;
			while(n % i == 0){
				mu++;
				n /= i;
			}
			if(mu >= 2){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = a; i <= b; i++){
		if(check(i)){
			printf("%d ", i);
		}
	}
	return 0;
}
