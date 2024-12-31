//3a
#include<stdio.h>
int main()
{
	int n,k;
	printf("Nhap k: ");
	scanf("%d",&k);
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	} while(n<=0 || n>10);
	for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            printf("*");
		}
		printf("\n");
	}
	return 0;
}
