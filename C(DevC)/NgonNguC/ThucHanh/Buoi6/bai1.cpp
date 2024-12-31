//bai 1
#include<stdio.h>
int TimSoDaoNguoc(int n){
	int t, s = 0;
	while(n>0){
		t = n % 10;
		s = s * 10 + t;
		n = n / 10;
	}
	return s;
}

int main()
{
	int n;
	printf("Nhap so nguyen bat ky: ");
	scanf("%d",&n);
	int SoDaoNguoc = TimSoDaoNguoc(n);
	printf("So dao nguoc cua %d la %d",n,SoDaoNguoc);
	return 0;
}
