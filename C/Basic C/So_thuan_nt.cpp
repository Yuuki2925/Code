//So thuan nt
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
int checknt(int n){
	while(n){
		int r = n % 10;
		if(r != 2 && r != 3 && r != 5 && r != 7)
			return 0;
		n /= 10;
	}
	return 1;
}
int tongnt(int n){
	int sum = 0;
	while(n){
		sum += n % 10;
		n /= 10;
	}
	if(nt(sum)){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int cnt = 0;
	for( int i = a; i <= b; i++){
		if(checknt(i) && nt(i) && tongnt(i)){ // toi uu if
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
