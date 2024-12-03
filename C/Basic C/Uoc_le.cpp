//Uoc le
#include <stdio.h>
#include <math.h>
int uocle(int n){
	double can = sqrt(n);
	if(can * can == n){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	if(uocle(n)){
		printf("YES\n");
	}
	else{
		printf("NO");
	}
	return 0;
}
