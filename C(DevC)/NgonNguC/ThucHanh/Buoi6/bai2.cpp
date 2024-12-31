//bai 2
#include<stdio.h>
float TinhTong(int n){
	float s = 0;
	for(int i=1; i<=n; i++){
		s = s + (float)i/(i+1);
	}
	return s;
}

int main()
{
	int n;
	printf("Nhap so nguyen: ");
	scanf("%d",&n);
	float s = TinhTong(n);
	printf("Ket qua la: %f",s);
	return 0;
}
