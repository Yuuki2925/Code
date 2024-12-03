// So thuan nghich
#include <stdio.h>
#include <math.h>
int tn(int n){
	int lat = 0;
	int temp = n;
	while(n){
		lat = lat * 10 + n % 10;
		n /= 10;
	}
	if(lat == temp){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", tn(n));
	return 0;
}
