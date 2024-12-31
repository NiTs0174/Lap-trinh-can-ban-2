/*
NAME:	NGUYEN MINH THANG
MSSV: 	2180601448
CLASS: 	21DTHC1
*/
#include <stdio.h>
#define MAX 100
/*--------------------DO THI (GRAPH)--------------------*/
//	KHAI BAO CAU TRUC
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI;
//READ FILE
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
			return 0;
	return 1;
}
//	KIEM TRA DO THI VO HUONG
int KiemTraDoThiVoHuong(DOTHI g){
	for(int i=0; i<g.n; i++)
		for(int j=0; j<g.n; j++)
			if(g.a[i][j] != g.a[j][i])
				return 0;
	return 1;
}
//	KIEM TRA DO THI CO TRONG SO
int KiemTraDoThiTrongSo(DOTHI g){
	for(int i=0; i<g.n; i++)
		for(int j=0; j<g.n; j++)
			if(g.a[i][j] > 1 || g.a[i][j] < 0)
				return 1;
	return 0;
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
	if(SoThanhPhanLT == 1)
		return 1;
	return 0;
}
/*--------------TIM DUONG DI NGAN NHAT VOI THUAT TOAN DIJKSTRA----------------*/
#define VOCUC 1000
int LuuVet[MAX];
int ChuaXet[MAX];
int DoDaiDuongDiToi[MAX];
//	TIM DUONG DI NHO NHAT
int TimDuongDiNhoNhat(DOTHI g){
	int li = -1;	//khong co dinh thoa
	float p = VOCUC;
	for(int i=0; i<g.n; i++){
		if(ChuaXet[i] == 0 && DoDaiDuongDiToi[i] < p){
			p = DoDaiDuongDiToi[i];
			li = i;
		}
	}
	return li;
}
// 	CAP NHAP DUONG DI
void CapNhatDuongDi(int u, DOTHI g){
	ChuaXet[u] = 1;		//chon dinh bat dau
	for(int v=0; v<g.n; v++){
		if(ChuaXet[v] == 0 && g.a[u][v] > 0 && g.a[u][v] < VOCUC){
			if(DoDaiDuongDiToi[v] > DoDaiDuongDiToi[u] + g.a[u][v]){
				DoDaiDuongDiToi[v] = DoDaiDuongDiToi[u] + g.a[u][v];
				LuuVet[v] = u;
			}
		}
	}
}
//	DIJKSTRA
void Dijkstra(int S, int F, DOTHI g){
	//khoi tao ban dau
	int i;
	for(i=0; i<g.n; i++){
		ChuaXet[i] = 0;
		DoDaiDuongDiToi[i] = VOCUC;
		LuuVet[i] = -1;
	}
	//thuat toan Dijkstra
	DoDaiDuongDiToi[S] = 0;
	while(ChuaXet[F] == 0){
		int u = TimDuongDiNhoNhat(g);
		if(u == -1)
			break;
		CapNhatDuongDi(u,g);
	}
	//xuat ket qua
	if(ChuaXet[F] == 1){	//thanh cong
		printf("Duong di ngan nhat tu dinh %d den dinh %d la: \n\t",S,F);
		i = F;
		printf("%d",F);
		while(LuuVet[i] != S){
			printf(" <- %d",LuuVet[i]);
			i = LuuVet[i];
		}
		printf(" <- %d\n",LuuVet[i]);
		printf("\tVoi do dai la %d\n",DoDaiDuongDiToi[F]);
	}
	else{
		printf("Khong co duong di tu dinh %d den dinh %d \n",S,F);
	}
}
/*----------------------THUAT TOAN FLOYD---------------------------*/
int Sau_Nut[MAX][MAX];
int L[MAX][MAX];
//	FLOYD
void Floyd(DOTHI g, int S, int F){
	//khoi tao ma tran Sau_Nut va L
	int i,j;
	for(i=0; i<g.n; i++){
		for(j=0; j<g.n; j++){
			if(g.a[i][j] > 0){
				Sau_Nut[i][j] = j;
				L[i][j] = g.a[i][j];
			}
			else{
				Sau_Nut[i][j] = -1;
				L[i][j] = VOCUC;
			}
		}
	}
	//thi hanh thuc toan Floyd
	for(int k=0; k<g.n; k++){
		for(i=0; i<g.n; i++){
			for(j=0; j<g.n; j++){
				if(L[i][j] > L[i][k] + L[k][j]){
					L[i][j] = L[i][k] + L[k][j];
					Sau_Nut[i][j] = Sau_Nut[i][k];
				}
			}
		}
	}
//	int S,F;
//	printf("nhap vao dinh bat dau: ");
//	scanf("%d",&S);
//	printf("nhap vao dinh ket thuc: ");
//	scanf("%d",&F);
	if(Sau_Nut[S][F] == -1){
		printf("Khong co duong di tu dinh %d den dinh %d la:\n",S,F);
	}
	else{
		printf("Duong di ngan nhat tu dinh %d den dinh %d la:\n",S,F);
		printf("\t%d",S);
		int u = S;
		while(Sau_Nut[u][F] != F){
			u = Sau_Nut[u][F];
			printf(" --> %d",u);
		}
		printf(" --> %d",F);
		printf("\n\tVoi tong trong so la %d",L[S][F]);
	}
}



/*-------------------------MAIN-------------------------------*/
int main(){
	DOTHI g;
	char inputfile[] = "dij1.graph";
//	char inputfile[] = "flo2.graph";

	if(DocMaTranKe(inputfile,g) == 1){
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(inputfile,g);
		
		if(KiemTraMaTranHopLe(g)==1){	//KIEM TRA HOP LE
			printf("\nDo thi HOP LE.\n");
			
			if(XetLienThong(g) == 1){	//XET LIEN THONG
				printf("Do thi LIEN THONG.\n");
				
				if(KiemTraDoThiTrongSo(g) == 1){	//KIEM TRA TRONG SO
					printf("Do thi CO trong so.\n");
					
					if(KiemTraDoThiVoHuong(g) == 1){	//KIEM TRA CO HUONG
						printf("Do thi VO huong.\n\n");	
						
						int s = 0;
						int f = 3;
						//DIJKSTRA
						Dijkstra(s,f,g);
						//FLOYD
						Floyd(g,s,f);
						
					}else	printf("Do thi CO huong.\n");
				}else	printf("Do thi KHONG trong so.\n");
			}else	printf("Do thi KHONG lien thong.\n");
		}else	printf("Do thi KHONG hop le.\n");
	}
	return 0;
}
