//Liet ke
//1. Dem so nt
//2. Dem so cp
//3. Dem so tn
//4. Dem so co tong la so nt
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

int cp(int n){
	int can = sqrt(n);
	if(can * can == n){
		return 1;
	}
	return 0;
}


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

int sumnt(int n){
	int sum = 0;
	while(n){
		sum += n % 10;
		n /= 10;
	}
	if(nt(sum)){
		return 1;
	}
	return 0;
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
	int cnt1 = 0;
	for(int i = 0; i < n; i++){
		if(nt(a[i])){
			++cnt1;
		}
	}
	printf("Dem so nt = %d\n", cnt1);
	int cnt2 = 0;
	for(int i = 0; i < n; i++){
		if(cp(a[i])){
			++cnt2;
		}
	}
	printf("Dem so cp = %d\n", cnt2);
	
	
	
	int cnt3 = 0;
	for(int i = 0; i < n; i++){
		if(tn(a[i])){
			++cnt3;
		}
	}
	printf("Dem so tn = %d\n", cnt3);
	
	
	int cnt4 = 0;
	for(int i = 0; i < n; i++){
		if(sumnt(a[i])){
			++cnt4;
		}
	}
	printf("Dem tong la nt = %d", cnt4);
	return 0;
}
