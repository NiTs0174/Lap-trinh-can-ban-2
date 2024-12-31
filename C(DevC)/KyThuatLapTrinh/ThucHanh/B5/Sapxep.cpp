#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void xuatmang(int a[],int n);
void sinhmang(int a[],int &n){
	do{
		printf("Nhap so pt: ");	scanf("%d",&n);
	}while(n<=0 || n>=100);
	srand(time(0));
	for(int i=0; i<n; i++){
		a[i] = rand()%101;
	}
	printf("Mang vua sinh ngau nhien:\n\t");
	xuatmang(a,n);
}
void xuatmang(int a[],int n){
	for(int i=0; i<n; i++){
		printf("%4d",a[i]);
	}
}
void swap(int &a,int &b){
	int tam = a;
	a = b;
	b = tam;
}
//sx tang dan
void interchange(int a[],int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i] > a[j]){
				swap(a[i],a[j]);
			}
		}
	}
}
void bubble(int a[],int n){
	for(int lan=0; lan<n-1; lan++){
		for(int j=0; j<n-1-lan; j++){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}
void bubble2(int a[],int n){
	for(int lan=0; lan<n-1; lan ++){
		for(int j=n-1; j>lan; j--){
			if(a[j] < a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
}
void selection(int a[],int n){
	for(int i=0; i<n-1; i++){
		int vtmin = i;
		for(int j=i+1; j<n; j++){
			if(a[j] < a[vtmin]){
				vtmin = j;
			}
		}
		swap(a[i],a[vtmin]);
	}
}
void insertion(int a[],int n){
	int vt, x;
	for(int i=1; i<n; i++){
		x = a[i];	
		vt = i-1;
		while(vt>=0 && a[vt] > x){
			a[vt+1] = a[vt];
			vt--;
		}
		a[vt+1] = x;
	}
}
void insertiongiam(int a[],int n){
	int vt, x;
	for(int i=1; i<n; i++){
		x = a[i];	
		vt = i-1;
		while(vt>=0 && a[vt] < x){
			a[vt+1] = a[vt];
			vt--;
		}
		a[vt+1] = x;
	}
}
void xuatmenu(int &chon){
	printf("\n1: Sinh mang\n");
	printf("2: Interchange Sort\n");
	printf("3: Buble Sort\n");
	printf("4: Selection Sort\n");
	printf("5: Insertion Sort\n");
	printf("0:THOAT\n");
	printf("Hay chon cong viec: ");	scanf("%d",&chon);
}

int main()
{
	int a[100],n,chon;
	do{
		xuatmenu(chon);
		switch(chon){
			case 1:
				sinhmang(a,n);	break;
			case 2:
				interchange(a,n);
				printf("Mang sau khi Interchange sort:\n\t");
				xuatmang(a,n);	
				break;
			case 3:
				bubble(a,n);
				printf("Mang sau khi Bubble sort:\n\t");
				xuatmang(a,n);	
				break;
			case 4:
				selection(a,n);
				printf("Mang sau khi Selection sort:\n\t");
				xuatmang(a,n);	
				break;
			case 5:
				char tanghaygiam;
				do{
					printf("\nSap xep tang hay giam(T/G): ");
					fflush(stdin);	scanf("%c",&tanghaygiam);
				}while(tanghaygiam != 't' && tanghaygiam != 'g' && tanghaygiam != 'T' && tanghaygiam != 'G');
				if(tanghaygiam == 'T' || tanghaygiam == 't'){					
					insertion(a,n);
					printf("Mang sau khi tang dan bang Insertion sort:\n\t");
				}
				else{
					insertiongiam(a,n);
					printf("Mang sau khi giam dan bang Insertion sort:\n\t");
				}
				xuatmang(a,n);	
				break;
			default: chon = 0;	break;
		}
	}while(chon != 0);
	return 0;
}
