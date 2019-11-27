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
	};//声明结构体框架 
	
	struct Book getinput(struct Book book) //定义函数，返回类型为Book结构体结构体作为函数的参数传递，注意参数的形式 
	{
		printf("输入书名：");
		scanf("%s",book.title);
		printf("input author:");
		scanf("%s",book.author);
		printf("输入日期：");
		scanf("%d %d %d",&book.date.year,&book.date.month,&book.date.day);
		printf("输入出版社：");
		scanf("%s",book.publisher);
	
		return book;
	}
	
	void printfbook(struct Book book)//注意函数类型是void,参数类型是Book结构体 
	{
		printf("书名：%s\n",book.title);
		printf("作者：%s\n",book.author);
		printf("日期：%d-%d-%d",book.date.year,book.date.month,book.date.day);
		printf("出版社：%s\n",book.publisher);
	}


int main(void)
{
	struct Book b1,b2;//定义结构体 
	
	printf("输入第一本:\n");
	b1=getinput(b1);//结构体b1作为参数传递 ，函数返回值重新赋给b1 
	
	printf("输入第二本:\n");
	b2=getinput(b2);
	
	putchar('\n'); 
	
	printf("输入完毕，开始打印\n");
	
	printf("第一本：\n");
	printfbook(b1);
	putchar('\n');
	printf("第一本：\n");
	printfbook(b1);
	
 } 
