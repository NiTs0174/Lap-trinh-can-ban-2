//2d1
#include<stdio.h>
int main()
{
	int n;
	long s=0;
	do{
		printf("Nhap n: ");
		scanf("%d",&n); 
	} while(n<=0);
	for(int i=1; i<=n; i++){
			s=s+i;
	}
	printf("s = %ld",s);
	return 0;
}
