/*
NAME:	NGUYEN MINH THANG
MSSV: 	2180601448
CLASS: 	21DTHC1
*/
#include <stdio.h>
#define  MAX 100
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
/*----------------------KHUNG CAY NHO NHAT (PRIM)---------------------------*/
int ChuaXet[MAX];
//	KHAI BAO CAU TRUC 'CANH'
typedef struct EDGE{
	int u;
	int v;
	int value;
}CANH;
CANH T[MAX];	//mang luu cac canh trong thuat toan Prim 
//	PRIM
void Prim(DOTHI g,int dxp){
	int nT = 0;		//khoi tao so luong cac CANH cua cay khung
	for(int i=0; i<g.n; i++)	//khoi tao danh sach cac DINH
		ChuaXet[i] = 0;
	ChuaXet[dxp] = 1;				//xet dinh 0 dau tien
	while(nT<g.n-1){
		T[MAX].value = MAX;
		for(int i=0; i<g.n; i++)
			if(ChuaXet[i] == 1)	//xem dinh i da xet
				for(int j=0; j<g.n; j++)
					if(ChuaXet[j]==0 && g.a[i][j]!=0 && T[MAX].value>g.a[i][j]){
						T[MAX].u = i;
						T[MAX].v = j;
						T[MAX].value = g.a[i][j];
					}
		T[nT++] = T[MAX];
		ChuaXet[T[MAX].v] = 1;	//dinh v da xet
	}
	int TongTrongSoCuaCayKhung = 0;
	printf("Cay khung nho nhat cua do thi la:\n");
	for(int i=0; i<nT-1; i++){
		printf("[%d,%d(%d)] ",T[i].u,T[i].v,T[i].value);
		TongTrongSoCuaCayKhung += T[i].value;
	}
	printf("[%d,%d(%d)] ",T[nT-1].u,T[nT-1].v,T[nT-1].value);
	TongTrongSoCuaCayKhung += T[nT-1].value;
	printf("\nTong trong so cua cay khung la: %d\n",TongTrongSoCuaCayKhung);
}
/*----------------------KHUNG CAY NHO NHAT (KRUSKAL)----------------------------*/
//	SAP XEP CANH
void SapXepCanh(CANH E[100], int tongsocanh){
	CANH canhtam;
	for(int i=0; i<tongsocanh-1; i++)
		for(int j=i+1; j<tongsocanh; j++)
			if(E[i].value > E[j].value){
				canhtam = E[i];
				E[i] = E[j];
				E[j] = canhtam;
			}
}
// 	KRUSKAL
void Kruskal(DOTHI g){
	CANH listEdge[MAX];
	int tongsocanh = 0;		//tongg so CANH trong do thi
	int i,j;
	for(i=0; i<g.n; i++)	//tien hanh them cac CANH trong do thi listEdge
		for(j=i+1; j<g.n; j++)
			if(g.a[i][j] > 0){
				listEdge[tongsocanh].u = i;
				listEdge[tongsocanh].v = j;
				listEdge[tongsocanh].value = g.a[i][j];
				tongsocanh++;
			}
			
	SapXepCanh(listEdge,tongsocanh);	//sap xep cac CANH co trong so tang dan
	
	int nT=0;		//khoi tao so luong cac CANH cua cay khung
	CANH T[MAX];	//chua cac CANH cua cay khung
	int nhan[MAX];	//chua cac NHAN cua cac dinh trong do thi theo thuat toan
	
	for(i=0; i<g.n; i++)
		nhan[i] = i;
	int canhdangxet = 0;	//CANH dang xet thu may trogn danh sach
	while(nT<g.n && canhdangxet<tongsocanh){
		if(nhan[listEdge[canhdangxet].u] != nhan[listEdge[canhdangxet].v]){
			T[nT] = listEdge[canhdangxet];
			nT++;
			int giatri =nhan[listEdge[canhdangxet].v];
			for(j=0; j<g.n; j++)
				if(nhan[j] == giatri)
					nhan[j] = nhan[listEdge[canhdangxet].u];
		}
		canhdangxet++;
	}
	if(nT != g.n-1)
		printf("\nDo thi khong lien thong nen khong co Kruskal\n");
	else{
		int TongTrongSoCuaCayKhung = 0;
		printf("Cay khung nho nhat cua do thi la:\n");
		for(i=0; i<nT; i++){
			printf("[%d,%d(%d)],",T[i].u,T[i].v,T[i].value);
			printf("\b ");
			TongTrongSoCuaCayKhung += T[i].value;
		}
		printf("\nNhan tat ca la [%d]",nhan[i]);
		printf("\nTong trong so cua cay khung la: %d\n",TongTrongSoCuaCayKhung);
	}
}



/*-------------------------MAIN---------------------------------*/
int main(){
	DOTHI g;
	char inputfile[] = "1.graph";
//	char inputfile[] = "Huong.graph";

	if(DocMaTranKe(inputfile,g) == 1){
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(inputfile,g);
		
		if(KiemTraMaTranHopLe(g)==1){	//KIEM TRA HOP LE
			printf("\nDo thi hop le.\n");
			
			if(XetLienThong(g) == 1){	//XET LIEN THONG
				printf("Do thi LIEN THONG.\n");
				
				if(KiemTraDoThiTrongSo(g) == 1){	//KIEM TRA TRONG SO
					printf("Do thi CO trong so.\n");
					
					if(KiemTraDoThiVoHuong(g) == 1){	//KIEM TRA CO HUONG
						printf("Do thi VO huong.\n\n");	
						
						//PRIM
						for(int dxp=0; dxp<g.n; dxp++)
							Prim(g,dxp);
						printf("\n============================================\n\n");
						//KRUSKAL
						Kruskal(g);
						
					}else	printf("Do thi CO huong.\n");
				}else	printf("Do thi KHONG trong so.\n");
			}else	printf("Do thi KHONG lien thong.\n");
		}else	printf("Do thi KHONG hop le.\n");
	}
	return 0;
}
