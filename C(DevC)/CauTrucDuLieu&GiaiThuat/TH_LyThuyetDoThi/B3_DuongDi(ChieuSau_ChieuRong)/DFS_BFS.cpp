/*
NAME:	NGUYEN MINH THANG
ID: 	2180601448
CLASS: 	21DTHC1
*/
#include <stdio.h>
#define MAX 20
/*--------------------DO THI (GRAPH)--------------------*/
//	DN DO THI
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
/*------------TIM KIEM DUONG DI THEO CHIEU SAU VA CHIEU RONG---------------*/
int LuuVet[MAX];
int ChuaXet[MAX];
// DFS
void DFS(int v, GRAPH g){
	ChuaXet[v] = 1;		//dinh v duoc xet
	int u;
	for(u=0; u<g.n; u++)
		if(g.a[v][u] != 0 && ChuaXet[u] == 0){	//dinh v,u ke nhau va u chua xet
			LuuVet[u] = v;
			DFS(u,g);
		}
}
//	XUAT DUONG DI
void XuatDuongDi(int s, int f){
	int i = f;
	printf("%d",f);
	while(i != s)
		printf(" <- %d",i=LuuVet[i]);
}
//	XUAT DUONG DI DQ
void XuatDuongDi_DQ(int s, int f){
	if(f != s)
		XuatDuongDi_DQ(s,LuuVet[f]);
	printf("%d -> ",f);
}
//3. DUYET THEO CHIEU SAU(DFS)
void DuyetTheoDFS(int s, int f, DOTHI g){
	int i;
	for(int i=0; i<g.n; i++){
		LuuVet[i] = -1;
		ChuaXet[i] = 0;
	}
	DFS(s,g);
	if(ChuaXet[f] == 1){
		printf("\n Duong di \"DFS\" tu dinh %d -> %d la:\n\t",s,f);
		XuatDuongDi_DQ(s,f);
		printf("\b\b\b  ");
	}
	else
		printf("\nKhong co duong di tu dinh %d -> %d.\n");
}
//=================================
// DN QUEUE
struct QUEUE{
	int size;
	int array[MAX];
};
//	KHOI TAO QUEUE
void KhoiTaoQueue(QUEUE &q){ 	//Init Queue
	q.size = 0;
}
//	DAY GIA TRI VAO QUEUE
int DayGiaTriVaoQueue(QUEUE &q, int value){		//Push
	if(q.size+1 >= 100)		//Is Full
		return 0;
	q.array[q.size] = value;
	q.size++;
	return 1;
}
//	LAY GIA TRI RA KHOI QUEUE
int LayGiaTriRaKhoiQueue(QUEUE &q, int &value){		//Pop
	if(q.size <= 0)		//Is Empty
		return 0;
	value = q.array[0];
	for(int i=0; i<q.size-1; i++)
		q.array[i] = q.array[i+1];
	q.size--;
	return 1;
}
//	KIEM TRA QUEUE RONG
int KiemTraQueueRong(QUEUE q){	//Is Empty
	if(q.size <= 0)
		return 1;
	return 0;
}
//	BFS
void BFS(int v, DOTHI g){
	QUEUE q;
	KhoiTaoQueue(q);
	DayGiaTriVaoQueue(q,v);
	while(!KiemTraQueueRong(q)){
		LayGiaTriRaKhoiQueue(q,v);
		ChuaXet[v] = 1;
		for(int u=0; u<g.n; u++)
			if(g.a[v][u] != 0 && ChuaXet[u] == 0 && LuuVet[u] == -1){
				DayGiaTriVaoQueue(q,u);
				LuuVet[u] = v;
			}
	}
}
//	DUYET THEO CHIEU RONG BFS
void DuyetTheoBFS(int s, int f, DOTHI g){
	for(int i=0; i<g.n; i++){
		LuuVet[i] = -1;
		ChuaXet[i] = 0;
	}
	BFS(s,g);
	if(ChuaXet[f] == 1){
		printf("\nDuong di \"BFS\" tu dinh %d -> %d la:\n\t",s,f);
		XuatDuongDi_DQ(s,f);
		printf("\b\b\b  ");
	}
	else printf("\nKhong co duong di tu dinh %d -> %d.\n");
}



/*-------------------------MAIN---------------------------------*/
int main(){
	DOTHI g;
	int s = 2;
	int f = 5;
	char inputfile[] = "5.graph";
	if(DocMaTranKe(inputfile,g) == 1){
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(inputfile,g);
		if(KiemTraMaTranHopLe(g) == 1){	//KIEM TRA HOP LE
			printf("\nDo thi hop le.\n");
			
			//DUYET THEO DFS
			DuyetTheoDFS(s,f,g);
			//DUYET THEO BFS
			DuyetTheoBFS(s,f,g);
			
		}
		else	
			printf("Do thi KHONG hop le.\n");
	}
	return 0;
}
