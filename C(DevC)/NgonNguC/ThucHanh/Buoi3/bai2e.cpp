//2e
#include<stdio.h>
int main()
{
	int n,cs;
	long s=0;
	do{
		printf("Nhap n: ");
		scanf("%d",&n); 
	} while(n<=0);
	while(n!=0){
		cs=n%10;
		s=s+cs;
		n=n/10;
	}
	printf("s = %ld",s);
	return 0;
}
