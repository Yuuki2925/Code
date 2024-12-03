// So chinh phuong
#include <stdio.h>
#include <math.h>
int cp(int n){
	int can = sqrt(n);
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
	printf("%d", cp(n));
	return 0;
}
