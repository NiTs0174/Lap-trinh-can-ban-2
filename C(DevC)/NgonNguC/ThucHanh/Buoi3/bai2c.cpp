//2c
#include<stdio.h>
int main()
{
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	} while(n<=0);
	for(int i=1; i<=n; i=i+1){
		if(i%2!=0 && i%3!=0){
			printf("\t%d",i);
		}
	}
	return 0;
}
