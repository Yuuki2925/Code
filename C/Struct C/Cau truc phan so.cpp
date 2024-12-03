//Cau truc phan so 
#include <stdio.h>
#include <math.h>
#include <string.h>
struct ps{
	int tu, mau;
};
typedef struct ps ps;

//tim phan so toi gian
int gcd(int a, int b){
	while(b != 0){
		int x = a % b;
		a = b;
		b = x;
	}
	return a;
}
int lcm(int a, int b){
	return a * b / gcd(a, b);
}

ps toigian(ps a){
	ps res;
	int uc = gcd(abs(a.tu), abs(a.mau));
	res.tu = a.tu / uc;
	res.mau = a.mau / uc;
	return res;
}

//Tim tong 2 phan so
ps tong(ps a, ps b){
	ps res;
	int mc = lcm(a.mau, b.mau);
	res.mau = mc;
	res.tu = mc / a.mau * a.tu + mc / b.mau * b.tu;
	return toigian(res);
}

//Tim hieu 2 phan so
ps hieu(ps a, ps b){
	ps res;
	int mc = lcm(a.mau, b.mau);
	res.mau = mc;
	res.tu = mc / a.mau * a.tu - mc / b.mau * b.tu;
	return toigian(res);
}
int main(){
	ps a, b, res;
	scanf("%d%d%d%d", &a.tu, &a.mau, &b.tu, &b.mau);
	res = toigian(a);
	res = toigian(b);
	printf("Phan so toi gian la:\n%d/%d\n%d/%d\n", res.tu, res.mau, res.tu, res.mau);
	ps t, h;
	t = tong(a, b);
	h = hieu(a, b);
	printf("Tong 2 phan so la:\n%d/%d\nHieu 2 phan so la:\n%d/%d", t.tu, t.mau, h.tu, h.mau);
	return 0;
}

