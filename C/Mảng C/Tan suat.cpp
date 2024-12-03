//Tan suat
#include <stdio.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n ; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		int check = 1;
		for(int j = 0; j < i; j++){
			if(a[i] == a[j]){
				check = 0;
				break;
			}
		}
		if(check == 1){
			int cnt = 1;
			for(int j = i + 1; j < n; j++){
				if(a[i] == a[j]){
					cnt++;
				}
			}
			printf("%d %d\n", a[i], cnt);
		}
	}
	return 0;
}
