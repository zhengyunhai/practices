#include<stdio.h>
#include<stdlib.h>

void getinput(struct Book *book);
void addbook(struct Book **library);
void printflibrary(struct Book *library);
void releselibrary(struct Book **library);

struct Book {
	char title[128];
	char author[48];
	struct Book *next;
};//������

void getinput(struct Book *book)//���ݵĲ����ǽṹ��ָ�� 
{
	printf("����������");
	scanf("%s",book->title); 
	printf("�������ߣ�");
	scanf("%s",book->author);
}

void addbook(struct Book **library)//����ͷָ��head�ĵ�ַ 
{
	struct Book *book;//����ṹ��ָ�� ���ֲ����� 
	static struct Book *tail;//���徲̬��ָ�룬ʹָ֮�������β��  
	
	book=(struct Book *)malloc(sizeof(struct Book));//����ռ� ��ע������ת�� 
	if(book==NULL)//����ʧ�� 
	{
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	
	getinput(book);
	
	
	//β�巨 
	if(*library==NULL)//������ ��ֻ��ͷָ�룬library��ͷָ�룬*library�ǵ�һ��Ԫ�صĵ�ַ 
	{
		*library=book;//ע��book��ָ�룬�����Ǵ��ݵ�ַ 
		book->next=NULL; 
	}
	else//�ǿ����� 
	{
		tail->next=book;
		book->next=NULL; 	
	}
	tail=book; 
 } 
 

void printflibrary(struct Book *library)//ע�����ﴫ�ݵĲ���library�ĵ�ַ������library���� 
{
	struct Book *book;
	int count=1;
	
	book=library;
	while(book!=NULL) //���ǿ�ָ��
	{
		printf("book %d:\n",count);
		printf("������%s",book->title);
		printf("���ߣ�%s\n",book->author);
		book=book->next;
		count++;
	 } 
} 


void releselibrary(struct Book **library)
{
	struct Book *temp;
	 
	while(*library!=NULL)
	{
		temp=*library;
		*library=(*library)->next;
		free(temp);;
	}
}


int main(void)
{
	struct Book *library=NULL;//����Ϊͷָ���ָ�� 
	char ch;
	
	while(1)
	{
		printf("�Ƿ������鼮��Y/N��:");
		do
		{
			ch=getchar();
		}while(ch!='Y'&&ch!='N');
		if(ch=='Y')
		{
			addbook(&library);//����ͷָ������ĵ�ַ 
		}
		else
		{
			break;
		}
	}
	
	printf("�Ƿ��ӡ��Y/N��\n");
	do
		{
			ch=getchar();
		}while(ch!='Y'&&ch!='N');
		
		if(ch=='Y')
		{
			printflibrary(library);
		}
	releselibrary(&library);
	
	
 } 
