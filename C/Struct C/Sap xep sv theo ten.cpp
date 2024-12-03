//Sap xep sinh vien theo ten
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct sv{
	char ten[100];
	char ns[100];
	char dc[100];
	float gpa;
	int stt;
};
typedef struct sv sv;

//In thong tin
void in(sv a){
	printf("%s %s %s %.2f\n", a.ten, a.ns, a.dc, a.gpa);
}

int cmp(const void *a, const void *b) {
    sv *x = (sv*)a;
    sv *y = (sv*)b;
    int name = strcmp(x->ten, y->ten);
    if (name != 0) {
        return name;
    }
	else {
        return x->stt - y->stt;
    }
}
int main(){
	int n;
	printf("So luong sinh vien: ");
	scanf("%d", &n);
	sv a[n];
	for(int i = 0; i < n; i++){
		getchar();
		printf("Sinh vien thu %d\n", i + 1);
		printf("Nhap ten sinh vien: ");
		gets(a[i].ten);
		printf("Nhap ngay sinh sinh vien: ");
		gets(a[i].ns);
		printf("Nhap dia chi sinh vien: ");
		gets(a[i].dc);
		printf("Nhap diem GPA: ");
		scanf("%f", &a[i].gpa);
		a[i].stt = i;
	}
	qsort(a, n, sizeof(sv), cmp);
	for(int i = 0; i < n; i++){
		in(a[i]);
	}
	return 0;
}

