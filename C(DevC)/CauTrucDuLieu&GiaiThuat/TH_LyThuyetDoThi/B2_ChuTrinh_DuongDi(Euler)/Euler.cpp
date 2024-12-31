/*
NAME:	NGUYEN MINH THANG
ID: 	2180601448
CLASS: 	21DTHC1
*/
#include <stdio.h>
#define MAX 20
/*--------------------DO THI (GRAPH)--------------------*/
//	DN CAU TRUC
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
//	DI TIM CAC DINH LIEN THONG
void DiTimCacDinhLienThong(DOTHI g, int nhan[MAX], int i){
	for(int j=0; j<g.n; j++)
		if(g.a[i][j] != 0 && nhan[j] != nhan[i]){
			nhan[j] = nhan[i];
			DiTimCacDinhLienThong(g,nhan,j); 
		}
}
//	XET LIEN THONG
int XetLienThong(DOTHI g){
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
	for(i=1; i<=SoThanhPhanLT; i++){
		for(int j=0; j<g.n; j++)
			if(nhan[j] == i)
				return 1;
		return 0;
	}
	if(SoThanhPhanLT == 1)	
		return 1;
	return 0;
}
/*-------------CHU TRINH & DUONG DI (EULER)-------------*/
//	DN CAU TRUC STACK
struct STACK{			
	int array[100];		//thu tu cac dinh trong chu trinh euler co toi da 100 dinh
	int size;			//so luong cac dinh
};
//	KHOI TAO STACK
void KhoiTaoStack(STACK &stack){	//Init Stack
	stack.size = 0;
}
//	DAY GIA TRI CAO STACK
void DayGiaTriVaoStack(STACK &stack, int value){	//Push	
	if(stack.size+1 >= 100)
		return;		//Is Full
	stack.array[stack.size] = value;
	stack.size++;
}
//============BAC===========
//	BAC CUA DINH
int BacCuaDinh(int dinh, DOTHI g){	//Vo huong va Bac ngoai: Co huong
	int bac = 0;
	for(int j=0; j<g.n; j++)
		if(g.a[dinh][j] != 0)
			bac++;
	return bac;
}
//	BAC TRONG CUA DINH
int BacTrongCuaDinh(int dinh, DOTHI g){		//Co huong
	int bac = 0;
	for(int i=0; i<g.n; i++)
		if(g.a[i][dinh] != 0)
			bac++;
	return bac;
}
//==============VO HUONG========
//	TIM DUONG DI
void TimDuongDi(int i, DOTHI &g, STACK &stack){
	for(int j=0; j<g.n; j++)
		if(g.a[i][j] != 0){
			g.a[i][j] = g.a[j][i] = 0;	//xoa canh
			TimDuongDi(j,g,stack);	
		}
	DayGiaTriVaoStack(stack,i);		//Push
}
//	KIEM TRA CHU TRINH & DUONG DI EULER
int Euler(int dxp, DOTHI g){
	int i,j;
	DOTHI temp = g;		//thong qua do thi trung gian
	STACK stack;
	KhoiTaoStack(stack);
	TimDuongDi(dxp,temp,stack);
	for(i=stack.size-1; i>0 ; i--)
		printf("%d -> ",stack.array[i]);
	printf("%d.\n",stack.array[0]);
	return 1;	//CO euler
}
//	DO THI VO HUONG
int Euler_DoThiVoHuong(DOTHI g){
	int SoDinhBacChan = 0, SoDinhBacLe =0;
	for(int dinh=0; dinh<g.n; dinh ++){
		if(BacCuaDinh(dinh,g)%2 ==0)	SoDinhBacChan++;
		else							SoDinhBacLe ++;
	}
	if(SoDinhBacLe ==0)			return 1;	//1: Chu trinh
	else if(SoDinhBacLe == 2)	return -1;	//-1: Duong di
	return 0;	//0: Khong Euler
}
//==============CO HUONG========
//	TIM DUONG DI
void TimDuongDi2(int i, DOTHI &g, STACK &stack){
	for(int j=0; j<g.n; j++)
		if(g.a[i][j] != 0){
			g.a[i][j] = 0;
			TimDuongDi2(j,g,stack);	
		}
	DayGiaTriVaoStack(stack,i);		//Push
}
//	KIEM TRA CHU TRINH & DUONG DI EULER
int Euler2(int dxp, DOTHI g){
	int i,j;
	DOTHI temp = g;		//thong qua do thi trung gian
	STACK stack;
	KhoiTaoStack(stack);
	TimDuongDi2(dxp,temp,stack);
	for(i=stack.size-1; i>0 ; i--)
		printf("%d -> ",stack.array[i]);
	printf("%d.\n",stack.array[0]);
	return 1;	//CO euler
}
//	DO THI CO HUONG
int Euler_DoThiCoHuong(DOTHI g){
	int dem = 0;
	for(int dinh=0; dinh<g.n; dinh ++)
		if(BacCuaDinh(dinh,g) != BacTrongCuaDinh(dinh,g))
			dem++;
	if(dem == 0)			return 1;	//1: Chu trinh
	else if(dem == 2)	return -1;	//-1: Duong di
	return 0;	//0: Khong Euler
}



/*------------------------MAIN----------------------------------*/
int main(){
	DOTHI g;
	char inputfile[] = "CE1.graph";
//	char inputfile[] = "DE.graph";
//	char inputfile[] = "CE_Huong.graph";
//	char inputfile[] = "DE_Huong.graph";
	
	if(DocMaTranKe(inputfile,g) == 1){
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(inputfile,g);
		
		if(KiemTraMaTranHopLe(g) == 1){		//KIEM TRA HOP LE
			printf("\nDo thi hop le.\n");
			
			if(XetLienThong(g) == 1){	//XET LIEN THONG
				printf("Do thi LIEN THONG.\n");
					
				if(KiemTraDoThiVoHuong(g)==1){	//XET CO HUONG
					printf("Do thi VO huong.\n");
					
					int LoaiDoThi = Euler_DoThiVoHuong(g);
					if(LoaiDoThi == 1){		//CHU TRINH EULER
						printf("\nChu Trinh Euler:\n");
						for(int d=0; d<g.n; d++)
							Euler(d,g);
					}
					else if(LoaiDoThi == -1){	//DUONG DI EULER
						printf("\nDuong Di Euler:\n");
						for(int d=0; d<g.n; d++)
							if(BacCuaDinh(d,g)%2 != 0)
								Euler(d,g);
					}else	printf("\nKHONG Euler.\n");
				}
				
				else{
					printf("Do thi CO huong.\n");
					
					int LoaiDoThi2 = Euler_DoThiCoHuong(g);
					if(LoaiDoThi2 == 1){	//CHU TRINH EULER
						printf("\nChu Trinh Euler:\n");
						for(int d=0; d<g.n; d++)
							Euler2(d,g);
					}
					else if(LoaiDoThi2 == -1){	//DUONG DI EULER
						printf("\nDuong Di Euler:\n");
						for(int d=0; d<g.n; d++)
							if(BacCuaDinh(d,g)-BacTrongCuaDinh(d,g) == 1)
								Euler2(d,g);
					}else	printf("\nKHONG Euler.\n");
				}
				
			}else	printf("Do thi KHONG lien thong.\n");
		}else	printf("Do thi KHONG hop le.\n");
	}
	return 0;
}
