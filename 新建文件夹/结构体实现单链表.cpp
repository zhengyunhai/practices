#include<stdio.h>
#include<stdlib.h>

struct Book {
	char title[128];
	char author[48];
	struct Book *next;
};//单链表

void getinput(struct Book *book)
{
	printf("输入书名：");
	scanf("%s",book->title); 
	printf("输入作者：");
	scanf("%s",book->author);
}

void addbook(struct Book **library)//library是头指针head的地址 
{
	struct Book *book,*temp;//定义结构体指针 ，局部变量 
	
	book=(struct Book *)malloc(sizeof(struct Book));//分配空间 ，注意类型转换 
	if(book==NULL)//分配失败 
	{
		printf("内存分配失败\n");
		exit(1);
	}
	
	getinput(book);
	
	if(*library==NULL)//空链表 
	{
		*library=book;//注意book是指针，这里是传递地址 
		book->next=NULL; 
	}
	else//非空链表 
	{
		temp=*library;
		*library=book;
		book->next=temp;
	}
 } 

void printflibrary(struct Book *library)//注意这里传递的不是library的地址，而是library本身 
{
	struct Book *book;
	int count=1;
	
	book=library;
	while(book!=NULL) //不是空指针
	{
		printf("book %d:\n",count);
		printf("书名：%s",book->title);
		printf("作者：%s",book->author);
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
	struct Book *library=NULL;//定义为头指针空指针 
	char ch;
	
	while(1)
	{
		printf("是否输入书籍（Y/N）:");
		do
		{
			ch=getchar();
		}while(ch!='Y'&&ch!='N');
		if(ch=='Y')
		{
			addbook(&library);//传递头指针自身的地址 
		}
		else
		{
			break;
		}
	}
	
	printf("是否打印（Y/N）\n");
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
