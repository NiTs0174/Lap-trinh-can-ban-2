#include<stdio.h>
#define MAX 100
//	Ghi vao File NUM.INP theo de 
void FileDe(int a[],int &n,int &p,int &x)
{
	FILE *f = fopen("NUM.INP","wt");
	if(f == NULL){
		printf("Khong mo duoc File!");
		return;
	}
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	fclose(f);
}
// Doc File NUM.INP va ghi ra man hinh
void ReadFile(int a[],int &n,int &p,int &x)
{
	FILE *f = fopen("NUM.INP","rt");
	if(f == NULL){
		printf("Khong mo duoc File!");
		return;
	}
	fscanf(f,"%3d",&n);
	fscanf(f,"%3d",&p);
	fscanf(f,"%3d",&x);
	printf("%3d%3d%3d\n",n,p,x);
	for(int i=0; i<n; i++){
		fprintf(f,"%3d",&a[i]);
	}
	fclose(f);
}
// Xuat mang
void XuatMang(int a[],int n)
{
	for(int i=0; i<n; i++){
		printf("%3d",a[i]);
	}
}
//a	Tim so lon hon x
int SoLonHonx(int a[],int n,int x)
{
	int dem = 0;
	for(int i=0; i<n; i++){
		if(a[i] > x){
			dem++;
		}
	}
	return dem;
}
//b Chen x vao vi tri p
void ChenxVaop(int a[],int &n,int p,int x)
{
	for(int i=n; i>=p; i--){
		a[i] = a[i-1];
	}
	a[p] = x;
	n++;
	
}
//	Ghi vao File NUM.OUT
void WriteFile(int a[],int n,int p,int x)
{
	FILE *f = fopen("NUM.OUT","wt");
	if(f == NULL){
		printf("Khong mo duoc file!");
		return;
	}
	fprintf(f,"\nCau a: %d",SoLonHonx(a,n,x));
	fprintf(f,"\nCau b: ");
	ChenxVaop(a,n,p,x);
	for(int i=0; i<n; i++){
		fprintf(f,"%3d",a[i]);
	}
	fclose(f);
}
//	Doc file NUM.OUT va ghi ra man hinh
void ReadFileResult()
{
	char arr[128];
	FILE *f = fopen("NUM.OUT","rt");
	if(f == NULL){
		printf("Khong mo duoc file!");
		return;
	}
	while(fgets(arr,128,f) != NULL){
		printf("%s",arr);
	}
	fclose(f);
}

int main()
{
	int a[MAX],n,p,x;
	FileDe(a,n,p,x);
	printf("NUM.INP\n");
	ReadFile(a,n,p,x);
	XuatMang(a,n);
	printf("\nNUM.OUT");
	WriteFile(a,n,p,x);
	ReadFileResult();
	return 0;
}
