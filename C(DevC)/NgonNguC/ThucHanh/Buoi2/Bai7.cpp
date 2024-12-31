#include<stdio.h>
int main()
{
	float km,cost;
	printf("Nhap so Km: ");
	scanf("%f",&km);
	
	if(km<=1){
		cost = 5000;
	}
	else if (km<=31){
		cost = (km-1)*4000 + 5000;
	}
	else{
		cost = (km-31)*3000 + 30*4000 + 5000;
	}
	printf("Tien cuoc Taxi la %.3f",cost);
	return 0;
}
