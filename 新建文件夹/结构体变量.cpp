#include<stdio.h>
struct Date
	{
		int year;
		int month;
		int day;
	};
	struct Book 
	{
		char title[128];
		char author[48];
		float price;
		struct Date date;
		char publisher[48];
	};//�����ṹ���� 
	
	struct Book getinput(struct Book book) //���庯������������ΪBook�ṹ��ṹ����Ϊ�����Ĳ������ݣ�ע���������ʽ 
	{
		printf("����������");
		scanf("%s",book.title);
		printf("input author:");
		scanf("%s",book.author);
		printf("�������ڣ�");
		scanf("%d %d %d",&book.date.year,&book.date.month,&book.date.day);
		printf("��������磺");
		scanf("%s",book.publisher);
	
		return book;
	}
	
	void printfbook(struct Book book)//ע�⺯��������void,����������Book�ṹ�� 
	{
		printf("������%s\n",book.title);
		printf("���ߣ�%s\n",book.author);
		printf("���ڣ�%d-%d-%d",book.date.year,book.date.month,book.date.day);
		printf("�����磺%s\n",book.publisher);
	}


int main(void)
{
	struct Book b1,b2;//����ṹ�� 
	
	printf("�����һ��:\n");
	b1=getinput(b1);//�ṹ��b1��Ϊ�������� ����������ֵ���¸���b1 
	
	printf("����ڶ���:\n");
	b2=getinput(b2);
	
	putchar('\n'); 
	
	printf("������ϣ���ʼ��ӡ\n");
	
	printf("��һ����\n");
	printfbook(b1);
	putchar('\n');
	printf("��һ����\n");
	printfbook(b1);
	
 } 
