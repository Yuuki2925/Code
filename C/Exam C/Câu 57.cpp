//Cau 57
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct nv{
	char mnv[100];
	char ten[100];
	int t;
};

typedef struct nv nv;

//In thong tin nhan vien
void in(nv a){
	printf("%s  %s  %d  ", a.mnv, a.ten, a.t);
}
int main(){
	int n;
	printf("Nhap danh sach nhan vien: ");
	scanf("%d", &n);
	nv a[n];
	for(int i = 0; i < n; i++){
		getchar();
		printf("Nhan vien thu %d\n", i + 1);
		printf("Nhap ma nhan vien: ");
		gets(a[i].mnv);
		printf("Nhap ho ten: ");
		gets(a[i].ten);
		printf("Nhap so tuoi: ");
		scanf("%d", &a[i].t);
	}
	printf("\nCac nhan vien o do tuoi nghi huu la:\n");
	for(int i = 0; i < n; i++){
		if(a[i].t >= 55){
			in(a[i]);
		}
	}
	return 0;
}
