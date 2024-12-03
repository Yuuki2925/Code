// Phan tich thua so nguyen to
#include <stdio.h>
#include <math.h>

int ptich(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			// su dung vong lap chia cho toi khi nao khong chia dc nua
			while(n % i == 0){
				printf("%d ", i);
				n /= i;
			}
		}
	}
	// Neu chua phan tich thua so nt xong ( n la 1 so nao do khac 1 k chia het dc cho i thi n chinh la so nt )
	if(n != 1){
		printf("%d ", n);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	ptich(n);
	return 0;
}
