#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int n;
	printf("Nhap so nguyen duong n: ");
	scanf("%u",&n);
	int x = sqrt(n);
	
	if(x*x == n){
		printf("%u la so chinh phuong",n);
	}
	else{
		printf("%u khong la so chinh phuong",n);
	}
	return 0;
}
