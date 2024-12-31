#include<stdio.h>
int main()
{
	float a,b;
	printf("Nhap a: ");
	scanf("%f",&a);
	printf("Nhap b: ");
	scanf("%f",&b);
	if(a == 0){
		if(b == 0){
			printf("Phuong trinh vo so nghiem");
		}
		else{
			printf("Phuong trinh vo nghiem");
		}
	}
	else{
		printf("Phuong trinh co nghiem x = %f",-b/a);
	}
	return 0;
}
