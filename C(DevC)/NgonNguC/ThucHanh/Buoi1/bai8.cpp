#include<stdio.h>
int main()
{
	float a,b,x;
	printf("Nhap a: ");
	scanf("%f", &a);
	printf("Nhap b: ");
	scanf("%f", &b);
	
	if (a==0)
		if(b==0)
			printf("Phuong trinh co vo so nghiem");
		else 
			printf("Phuong trinh vo nhgiem");
	else
		printf("Phuong trinh co 1 nghiem: %f",-b/a);

	return 0;
}
