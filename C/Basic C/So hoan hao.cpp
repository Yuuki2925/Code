//So hoan hao
#include <stdio.h>
#include <math.h>
#define ll long long
int nt(int n){
	if(n < 2){
		return 0;
	}
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}
int hh(ll n){
	for(int p = 2; p <= 32; p++){
		if(nt(p)){
			ll tmp = (ll)pow(2, p) - 1;
			if(nt(tmp)){
				ll num = (ll)pow(2, p - 1) * tmp;
				printf("%lld\n", num);
				if(num == n)
					return 1;
			} 
		}
	}
	return 0;
}
int main(){
	ll n;
	scanf("%lld", &n);
	if(hh(n)){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
