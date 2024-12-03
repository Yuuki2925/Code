//Cau truc so phuc
#include <stdio.h>
#include <math.h>
#include <string.h>

struct sp{
	int thuc, ao;
};
typedef struct sp sp;

//Tinh tong 2 so phuc
sp tong(sp a, sp b){
	sp res;
	res.thuc = a.thuc + b.thuc;
	res.ao = a.ao + b.ao;
	return res;
}

//Tinh hieu 2 so phuc
sp hieu(sp a, sp b){
	sp res;
	res.thuc = a.thuc - b.thuc;
	res.ao = a.ao - b.ao;
	return res;
}

//Tinh tich 2 so phuc
sp tich(sp a, sp b){
	sp res;
	res.thuc = a.thuc * b.thuc - a.ao * b.ao;
	res.ao = a.ao * b.thuc + a.thuc * b.ao;
	return res;
}

int main(){
	sp a, b, res;
	scanf("%d%d%d%d", &a.thuc, &a.ao, &b.thuc, &b.ao);
	res = tong(a, b);
	printf("%d + %di\n", res.thuc, res.ao);
	res = hieu(a, b);
	printf("%d - %di\n", res.thuc, res.ao);
	res = tich(a, b);
	printf("%d + %di\n", res.thuc, res.ao);
	return 0;
}
