#include<stdio.h>
// Day FIBONACI
int Fib(int n){
	if(n == 1 || n == 2){
		return 1;
	}
	return Fib(n-2)	+ Fib(n-1);
}

int main()
{
	int n;
	do{
		printf("Nhap n(>0): ");	scanf("%d",&n);
	}while(n <= 0);
	printf("\nGia tri cua cua so thu %d trong day Fibonaci la %d",n,Fib(n));
	printf("\n\tDay so FIBONACI den so %d:\n",n);
	for(int i=1; i<=n; i++){
		printf("%3d",Fib(i));
	}
	return 0;
}
