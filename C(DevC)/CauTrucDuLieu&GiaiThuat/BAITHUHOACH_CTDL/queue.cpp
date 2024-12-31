//QUEUE(HANG DOI)
#include<stdio.h>
#include<stdlib.h>
//DN CAU TRUC
struct node
{ 
	int data;
	node *next;
};
struct queue
{
	node *front;
	node *rear;
};
//KHOI DONG
void init(queue &q)
{
	q.front = NULL;
	q.rear = NULL;
}
//TAO NUT
node* createNode(int x)
{
	node *p = new node;
	if(p == NULL){
		printf("Khong du bo nho!!");
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
//KT RONG
int isEmpty(queue q)
{
	if(q.front == NULL)
		return 1;
	return 0;
}
//CHEN
void insert(queue &q, node *p)
{
	if(q.front == NULL)
	{
		q.front = p;
		q.rear = p;
	}
	else{
		q.rear->next = p;
		q.rear = p;
	}
}
//XOA
int remove(queue &q){
	int x;
	node *p = NULL;
	if(!isEmpty(q))
	{
		p = q.front;
		x = p->data;
		q.front = q.front->next;
		delete p;
		if(q.front == NULL)
			q.rear = NULL;
	}
	return x;
}
//NHAP QUEUE
void input(queue &q, int n)
{
	for(int i = 0; i< n; i++)
	{
		int x;
		printf("Nhap phan tu vao hang cho: ");	scanf("%d", &x);
		node *p = createNode(x);
		insert(q,p);
	}
}
//XUAT QUEUE
void output(queue q)
{
	for(node *p = q.front; p!= NULL; p=p->next)
		printf("%d\t", p->data);
}



int main(){
	queue q;
	init(q);
	int n;
	printf("Nhap so luong pt: ");	scanf("%d", &n);
//INPUT, OUTPUT
	input(q, n);
	printf("CAC PHAN TU TRONG HANG CHO DOI LA:\n");
	output(q);
//INSERT
	int x;
	printf("\nNhap pt can them: ");	scanf("%d", &x);
	node *p = createNode(x);
	insert(q,p);
    printf("\nHANG DOI SAU KHI THEM:\n");
    output(q);
//REMOVE
    printf("\nHANG DOI SAU KHI XOA:\n");
    remove(q);
    output(q);
	return 0;
}
