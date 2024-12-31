#include<stdio.h>
int main()
{
	int a,b,max1;
	printf("Nhap a: ");
	scanf("%d",&a);
	printf("Nhap b: ");
	scanf("%d",&b);
	
	max1 = a;
	if (max1<b)
		printf("Gia tri lon nhat la b: %d\n",b);
	else 
		printf("Gia tri lon nhat la a: %d\n",a);
	
	int x,y,z,max2;
	printf("Nhap x: ");
	scanf("%d",&x);
	printf("Nhap y: ");
	scanf("%d",&y);
	printf("Nhap z: ");
	scanf("%d",&z);
	
	max2 = x;
	if (max2 < y)
		max2 = y;
	
	if (max2 < z)
		max2 = z;
	printf("GTLN la %d",max2);

	return 0;
}
