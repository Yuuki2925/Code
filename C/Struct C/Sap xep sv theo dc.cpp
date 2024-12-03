//Sap xep sinh vien theo dia chi
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct sv{
	char ten[100];
	char ns[100];
	char dc[100];
	float gpa;
};
typedef struct sv sv;
void in(sv a){
	printf("%s %s %s %.2f\n", a.ten, a.ns, a.dc, a.gpa);
}

//So sanh
int cmp(const void *a, const void *b){
	sv *x = (sv*)a;
	sv *y = (sv*)b;
	if(strcmp(x->dc, y->dc) != 0){
		return strcmp(x->dc, y->dc);
	}
	else{
		if(x->gpa > y->gpa){
			return -1;
		}
		else{
			return 1;
		}
	}
}
int main(){
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	sv a[n];
	for(int i = 0; i < n; i++){
		getchar();
		printf("Sinh vien thu %d\n", i + 1);
		printf("Nhap ten: ");
		gets(a[i].ten);
		printf("Nhap ngay sinh: ");
		gets(a[i].ns);
		printf("Nhap dia chi: ");
		gets(a[i].dc);
		printf("Nhap GPA: ");
		scanf("%f", &a[i].gpa);
	}
	qsort(a, n, sizeof(sv), cmp);
	for(int i = 0; i < n; i++){
		in(a[i]);
	}
}
