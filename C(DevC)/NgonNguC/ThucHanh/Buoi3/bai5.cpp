#include<stdio.h>
int main()
{
	printf("BANG CUU CHUONG");
	for(int i=1; i<=9; i++){
		printf("\nBANG NHAN %d\n", i);
        for(int j = 1; j <= 10; j++){
            printf("\t%d x %d = %d\n", i, j, i*j);
		}
	}
	return 0;
}
