#include<stdio.h>
//UOC SO CHUNG LON NHAT
int UCLN(int x,int y){
	if(x == 0){
		return y;
	}
	return UCLN(y%x,x);
}
//BOI SO CHUNG NHO NHAT
int BCNN(int x,int y){
	if(x == 0){
		return 0;
	}
	return (x*y)/UCLN(x,y);
}

int main()
{
	int a,b;
	printf("Nhap 2 so nguyen duong: ");	scanf("%d%d",&a,&b);
	printf("\nUCLN(%d,%d) = %d",a,b,UCLN(a,b));
	printf("\nBCNN(%d,%d) = %d",a,b,BCNN(a,b));
	return 0;
}
