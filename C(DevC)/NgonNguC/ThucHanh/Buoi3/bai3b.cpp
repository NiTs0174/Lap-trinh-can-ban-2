//3b
#include<stdio.h>
int main() {
	int n,i,j;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	} while(n<=0 || n>10);
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++){
        printf("* ");
    	}
    	printf("\n");
	}
	return 0;
}
