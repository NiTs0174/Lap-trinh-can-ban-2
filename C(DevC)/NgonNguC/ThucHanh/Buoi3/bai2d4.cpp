//2d4
#include<stdio.h>
int main()
{
	int x,n,i;
	long s;
	printf("Nhap x: ");
	scanf("%d",&x);
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	} while(n <= 0);
	for(s=1, i=1; i<=n; i++){
		s = s * x;
	}
	printf("S = %d",s);
	return 0;
}
