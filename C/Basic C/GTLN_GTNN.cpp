// Tim GTLN va GTNN trong 4 so
// Cach 1:
#include <stdio.h>
#include <math.h>
int main(){
	long long a, b, c, d; 
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	int res1 = fmin(fmin(a,b),fmin(c,d));
	int res2 = fmax(fmax(a,b),fmax(c,d));
	printf("%lld %lld", res2, res1);
	return 0;
}


//Cach 2:
//#include <stdio.h>
//#include <math.h>
//int main(){
//	long long a, b, c, d; 
//	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
//	int min = a, max = a;
//	if(b < min) min = b;
//	if(c < min) min = c;
//	if(d < min) min = d;
//	if(b > max) max = b;
//	if(c > max) max = c;
//	if(d > max) max = d;
//	printf("%lld %lld", max,min);
//	return 0;
//}
