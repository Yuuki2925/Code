//So thuan nghich co 3 uoc nt
#include <stdio.h>
#include <math.h>
int tn(int n){
	int lat = 0;
	int tmp = n;
	while(n){
		lat = lat * 10 + n % 10;
		n /= 10;
	}
	if(tmp == lat){
		return 1;
	}
	else{
		return 0;
	}
}
int check(int n){
	int cnt = 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			cnt++;
			while(n % i == 0){
				n /= i;
			}
		}
	}
	if(n > 1){
		cnt++;
	}
	if(cnt >= 3){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int a, b;
	int so = 0;
	scanf("%d%d", &a, &b);
	for(int i = a; i <= b; i++){
		if(tn(i) && check(i)){
			printf("%d ", i);
			so = 1;
		}
	}
	if(so == 0){
		printf("-1");
	}
	return 0;
}
