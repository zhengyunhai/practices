#include<stdio.h>
#include<stdlib.h>

struct Book {
	char title[128];
	char author[48];
	struct Book *next;
};//������

void getinput(struct Book *book)
{
	printf("����������");
	scanf("%s",book->title); 
	printf("�������ߣ�");
	scanf("%s",book->author);
}

void addbook(struct Book **library)//library��ͷָ��head�ĵ�ַ 
{
	struct Book *book,*temp;//����ṹ��ָ�� ���ֲ����� 
	
	book=(struct Book *)malloc(sizeof(struct Book));//����ռ� ��ע������ת�� 
	if(book==NULL)//����ʧ�� 
	{
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	
	getinput(book);
	
	if(*library==NULL)//������ 
	{
		*library=book;//ע��book��ָ�룬�����Ǵ��ݵ�ַ 
		book->next=NULL; 
	}
	else//�ǿ����� 
	{
		temp=*library;
		*library=book;
		book->next=temp;
	}
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
		printf("���ߣ�%s",book->author);
		book=book->next;
		count++;
	 } 
} 


void releselibrary(struct Book *library)
{
	while(library!=NULL)
	{
		library=library->next;
		free(library);;
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
	releselibrary(library);
	
	
 } 
