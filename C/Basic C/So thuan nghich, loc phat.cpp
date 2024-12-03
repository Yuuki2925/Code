// So thuan nghich, loc phat
#include <stdio.h>
#include <math.h>
int tn(int n){
	int lat = 0;
	int tmp = n;
	while(n){
		lat = lat * 10 + n % 10;
		n /= 10;
	}
	return lat == tmp;
}
int check6(int n){
	while(n != 0){
		int r = n % 10;
		if(r == 6){
			return 1;
		}
		n /= 10;
	}
	return 0;
}
int tong(int n){
	int sum = 0;
	while(n){
		sum += n % 10;
		n /= 10;
	}
	if(sum % 10 == 8){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = a; i <= b; i++){
		if(tn(i) && check6(i) && tong(i)){
			printf("%d ", i);
		}
	}
	return 0;
}
