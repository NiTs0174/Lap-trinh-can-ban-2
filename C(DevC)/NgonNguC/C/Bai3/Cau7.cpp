#include<stdio.h>
int main()
{
	long n;
//7a
	do{	
		printf("Nhap n: ");
		scanf("%ld",&n);
		if(n <= 0)
			printf("Nhap sai, nhap lai\n");
	} while(n <= 0);
//7b
	int tam = 0;
	long tong = 0;
	while(n > 0){
		tam = n%10;
		tong = tong + tam;
		n = n/10;
	}
	printf("Tong cac chu so cua n = %ld",tong);
	return 0;
}
