/*
NAME:	NGUYEN MINH THANG
MSSV: 	2180601448
CLASS: 	21DTHC1
*/
#include <stdio.h>
#define  MAX 20
/*--------------------DO THI (GRAPH)--------------------*/
//	KHAI BAO CAU TRUC
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI;
//	READ FILE
int DocMaTranKe(char TenFile[100], DOTHI &g){
	FILE* f = fopen(TenFile,"rt");
	if(f == NULL){
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i=0; i<g.n; i++)
		for(int j=0; j<g.n; j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
	return 1;
}
//	OUTPUT
void XuatMaTranKe(char inputfile[], DOTHI g){
	printf("So dinh cua do thi la %d\n",g.n);
	printf("Ma tran ke cua do thi (%s) la \n\n",inputfile);
	for(int i=0; i<g.n; i++){
		for(int j=0; j<g.n; j++)
			printf("%4d",g.a[i][j]);
		printf("\n");
	}
}
//	KIEM TRA MA TRAN HOP LE
int KiemTraMaTranHopLe(DOTHI g){
	for(int i=0; i<g.n; i++)
		if(g.a[i][i] != 0)
			return 0;	//KHONG hop le
	return 1;	//hop le
}
//	KIEM TRA DO THI VO HUONG
int KiemTraDoThiVoHuong(DOTHI g){
	for(int i=0; i<g.n; i++)
		for(int j=0; j<g.n; j++)
			if(g.a[i][j] != g.a[j][i])
				return 0;	//CO huong
	return 1;	//VO huong
}
//	KIEM TRA DO THI CO TRONG SO
int KiemTraDoThiTrongSo(DOTHI g){
	for(int i=0; i<g.n; i++)
		for(int j=0; j<g.n; j++)
			if(g.a[i][j] > 1 || g.a[i][j] < 0)
				return 1;	//CO trong so
	return 0;	//KHONG trong so
}
//	DI TIM CAC DINH LIEN THONG
void DiTimCacDinhLienThong(DOTHI g, int nhan[MAX], int i){
	for(int j=0; j<g.n; j++)
		if(g.a[i][j] != 0 && nhan[j] != nhan[i]){
			nhan[j] = nhan[i];
			DiTimCacDinhLienThong(g,nhan,j); 
		}
}
//	XET LIEN THONG
void XetLienThong(DOTHI g){
	int nhan[MAX];
	int i;
	for(i=0; i<g.n; i++)
		nhan[i] = 0;
	int SoThanhPhanLT = 0;
	for(i=0; i<g.n; i++)
		if(nhan[i] == 0){
			SoThanhPhanLT++;
			nhan[i] = SoThanhPhanLT;
			DiTimCacDinhLienThong(g,nhan,i);
		}
	printf("\n-----------------------------------------\n");
	printf("So thanh phan lien thong la %d\n",SoThanhPhanLT);
	for(i=1; i<=SoThanhPhanLT; i++){
		printf("Thanh phan lien thong thu %d gom cac dinh:",i);
		for(int j=0; j<g.n; j++)
			if(nhan[j] == i)
				printf("%4d",j);
		printf("\n");
	}
}



/*-------------------------MAIN---------------------------------*/
int main(){
	DOTHI g;
	char inputfile[] = "0.graph";
	if(DocMaTranKe(inputfile,g)==1){
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(inputfile,g);
		//KIEM TRA HOP LE
		if(KiemTraMaTranHopLe(g)==1){
			printf("Do thi hop le.\n");
			//KIEM TRA VO HUONG
			if(KiemTraDoThiVoHuong(g)==1)	printf("Do thi VO huong.\n");
			else 							printf("Do thi CO huong.\n");
			//KIEM TRA TRONG SO
			if(KiemTraDoThiTrongSo(g)==1)	printf("Do thi CO trong so.\n");
			else 							printf("Do thi KHONG trong so.\n");
			//XET LIEN THONG
			XetLienThong(g);
		}
		else
			printf("Do thi KHONG hop le.\n");
	}
	return 0;
}
