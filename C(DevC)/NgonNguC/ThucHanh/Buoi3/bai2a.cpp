//2a
#include<stdio.h>
int main()
{
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);	
	} while(n<=0);
	for(int i=1; i<=n; i++){
		printf("\t%d",i);
	}
	return 0;
}
