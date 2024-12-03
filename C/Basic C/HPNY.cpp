// HPNY
#include <stdio.h>
#include <math.h>
int main(){
	int h, m;
	scanf("%d%d", &h, &m);
	int gio, phut, res;
	if (0 <= h && h <= 24 && 0 <= m && m <= 60){
		phut = 60 * 24;
		gio = h * 60;
		res = phut - gio - m;
		printf("%d", res);
	}
	
	return 0;
}
