// Tong uoc, dem uoc
#include <stdio.h>
#include <math.h>

// tong uoc
int tonguoc(int n){
	int sum;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			sum += i;
			if(n / i != i)
				sum += n / i;
		}
	}
	return sum;
}

// dem uoc
int demuoc(int n){
	int cnt = 0;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			++cnt;
			if(n / i != i){
				++cnt;
			}
		}
	}
	return cnt;
}


int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", tonguoc(n));
	printf("%d", demuoc(n));
	return 0;
}
