//So nguyen to
#include <stdio.h>
#include <math.h>
int nguyento(int n){
	if(n < 2){
		return 0;
	}
	else if(n == 2){
		return 1;
	}
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			return 0;
		}
		return 1;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	if(nguyento(n) == 1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
