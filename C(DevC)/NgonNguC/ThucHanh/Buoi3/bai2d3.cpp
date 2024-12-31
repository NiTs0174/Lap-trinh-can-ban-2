//2d3
#include<stdio.h>
int main()
{
	int n;
	float s=0;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	} while(n<=0);
	for(int i=1; i<=n; i++){
			s=s+(float)i/(i+1);
		}
		printf("s = %f",s);
	return 0;
}
