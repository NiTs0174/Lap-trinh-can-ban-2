//6a
#include <stdio.h>
#include <math.h>
int main(){
    int n,i,d;
    do{
    	printf("Nhap n = ");
    	scanf("%d", &n);
	} while(n<=0);
	for(d=0, i=1; i<=n; i++){
		if(n % i == 0){
			d = d + 1;
		}
	}
	printf("Cac so nguyen to: ");
	if(d == 2){
		printf("\t%d",i);
	}
	return 0;
}
