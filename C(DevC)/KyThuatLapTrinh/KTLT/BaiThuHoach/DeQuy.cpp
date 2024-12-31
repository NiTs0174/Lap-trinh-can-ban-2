#include<stdio.h>
#define MAX 100
void Nhap(int &n)
{
	do{
		printf("Nhap n: ");	scanf("%d",&n);
	}while(n <= 0);
}
//a Tinh bang DE QUY
float TongDQ(int n)
{
	if(n == 0){
		return 0;
	}
	return TongDQ(n-1) + (float)n/(n+1);
}
//b Khong tinh bang de quy
float Tong(int n)
{
	float s = 0;
	for(int i=1; i<=n; i++){
		s += (float)i/(i+1);
	}
	return s;
}

int main()
{
	int n;
	Nhap(n);
	float s1 = TongDQ(n);
	printf("S(DQ) = %f",s1);
	float s2 = Tong(n);
	printf("\nS = %f",s2);
	return 0;
}
